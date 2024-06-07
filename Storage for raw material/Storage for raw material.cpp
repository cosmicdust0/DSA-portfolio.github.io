#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Product {
    int id;
    char name[50];
    int demand;
    int location;
    int stock;
} Product;

typedef struct Node {
    Product product;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

typedef struct StorageUnit {
    int id;
    int capacity;
    char type[20];
    int available_space;
} StorageUnit;

typedef struct DAGNode {
    StorageUnit unit;
    struct DAGNode* next;
} DAGNode;

typedef struct OpenListItem {
    StorageUnit unit;
    int score;
    struct OpenListItem* next;
} OpenListItem;

Node* searchAVLTree(Node* root, int productID) {
    if (root == NULL || root->product.id == productID)
        return root;
    if (productID < root->product.id)
        return searchAVLTree(root->left, productID);
    return searchAVLTree(root->right, productID);
}

StorageUnit* findProduct(Node* productTree, int productID, DAGNode* warehouseLayout) {
    Node* productNode = searchAVLTree(productTree, productID);
    if (productNode == NULL) {
        printf("Product ID %d not found in product tree.\n", productID);
        return NULL;
    }

    DAGNode* current = warehouseLayout;
    while (current != NULL) {
        if (current->unit.id == productNode->product.location) {
            return &current->unit;
        }
        current = current->next;
    }

    printf("Storage unit ID %d not found in warehouse layout.\n", productNode->product.location);
    return NULL;
}

int estimateDistance(Product product, StorageUnit unit);
Node* insertProduct(Node* root, Product product);

OpenListItem* openListHead = NULL;

#define TABLE_SIZE 100
int closedList[TABLE_SIZE] = {0};

void addToClosedList(int unitID) {
    int index = unitID % TABLE_SIZE;
    closedList[index] = 1;
}

bool isInClosedList(int unitID) {
    int index = unitID % TABLE_SIZE;
    return closedList[index] == 1;
}

void addToOpenList(StorageUnit unit, int score) {
    OpenListItem* newItem = (OpenListItem*)malloc(sizeof(OpenListItem));
    newItem->unit = unit;
    newItem->score = score;

    if (!openListHead || score <= openListHead->score) {
        newItem->next = openListHead;
        openListHead = newItem;
        return;
    }

    OpenListItem* current = openListHead;
    while (current->next && score > current->next->score) {
        current = current->next;
    }
    newItem->next = current->next;
    current->next = newItem;
}

StorageUnit removeFromOpenListWithLowestScore() {
    if (!openListHead) {
        printf("Open list is empty\n");
        return (StorageUnit){0};
    }

    OpenListItem* temp = openListHead;
    StorageUnit unit = temp->unit;
    openListHead = openListHead->next;
    free(temp);
    return unit;
}

int estimateDistance(Product product, StorageUnit unit) {
    return abs(product.id - unit.id);
}

int height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* insertProduct(Node* root, Product product) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->product = product;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (product.id < root->product.id) {
        root->left = insertProduct(root->left, product);
    } else if (product.id > root->product.id) {
        root->right = insertProduct(root->right, product);
    } else {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && product.id < root->left->product.id) {
        return rightRotate(root);
    }
    if (balance < -1 && product.id > root->right->product.id) {
        return leftRotate(root);
    }
    if (balance > 1 && product.id > root->left->product.id) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && product.id < root->right->product.id) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void placeProduct(Node* productTree, Product product, DAGNode* warehouseLayout) {
    StorageUnit startingUnit;
    if (product.location != -1) {
        StorageUnit* unit = findProduct(productTree, product.id, warehouseLayout);
        if (unit != NULL) {
            startingUnit = *unit;
        } else {
            startingUnit = warehouseLayout->unit;
        }
    } else {
        startingUnit = warehouseLayout->unit;
    }
    int startingScore = estimateDistance(product, startingUnit);
    addToOpenList(startingUnit, startingScore);

    while (openListHead) {
        StorageUnit currentUnit = removeFromOpenListWithLowestScore();
        addToClosedList(currentUnit.id);

        if (currentUnit.available_space >= product.stock) {
            printf("Product %d (%s) can be placed in storage unit %d\n", product.id, product.name, currentUnit.id);
            product.location = currentUnit.id;
            return;
        }

        for (DAGNode* neighbor = warehouseLayout; neighbor; neighbor = neighbor->next) {
            if (!isInClosedList(neighbor->unit.id)) {
                int tentativeScore = estimateDistance(product, neighbor->unit) + estimateDistance(product, currentUnit);
                addToOpenList(neighbor->unit, tentativeScore);
            }
        }
    }

    printf("No suitable storage unit found for product %d (%s)\n", product.id, product.name);
}

int main() {
    Node* productTree = NULL;
    DAGNode* warehouseLayout = NULL;

    DAGNode* unit1 = (DAGNode*)malloc(sizeof(DAGNode));
    unit1->unit.id = 1;
    unit1->unit.capacity = 100;
    unit1->unit.available_space = 50;
    strcpy(unit1->unit.type, "Shelf");
    unit1->next = NULL;

    DAGNode* unit2 = (DAGNode*)malloc(sizeof(DAGNode));
    unit2->unit.id = 2;
    unit2->unit.capacity = 100;
    unit2->unit.available_space = 75;
    strcpy(unit2->unit.type, "Bin");
    unit2->next = unit1;

    warehouseLayout = unit2;

    Product newProduct = {10, "Beverage A", 200, -1, 50};
    placeProduct(productTree, newProduct, warehouseLayout);

    return 0;
}
