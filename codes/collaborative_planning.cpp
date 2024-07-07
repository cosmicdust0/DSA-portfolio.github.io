// Collaborative Demand and Supply Planning
// Using B-Tree
// Assumes BTreeNode struct
void insertNonFull(BTreeNode* x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && k < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && k < x->keys[i]) i--;
        i++;
        if (x->C[i]->n == 2 * t - 1) {
            splitChild(x, i, x->C[i]);
            if (k > x->keys[i]) i++;
        }
        insertNonFull(x->C[i], k);
    }
}
