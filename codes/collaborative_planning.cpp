// Using B-Tree for Collaborative Demand and Supply Planning was one of toughest to 
// learn and implement but here is the base code for insertion as a sample
// i have assumed the b-tree  standard struct
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
