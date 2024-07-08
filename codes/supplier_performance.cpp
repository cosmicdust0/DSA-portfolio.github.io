
//  ill be using red-black tree
// lets assumes RBNode
// struct with 
// key, value, color, left, right, parent
// hence here is the implementationof the RB tree
void insertFixup(RBNode* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode* y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
             // Symmetric cases (left and right exchanged)
            // Implementation is just the mirror image of the above
        }
    }
    root->color = BLACK;
}

