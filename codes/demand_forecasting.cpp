
// Demand Forecasting System
// Using Segment Trees
// Assumes SegTree struct with left, right, sum
void updateSegTree(SegTree* node, int l, int r, int idx, int val) {
    if (l == r) {
        node->sum += val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) updateSegTree(node->left, l, mid, idx, val);
    else updateSegTree(node->right, mid + 1, r, idx, val);
    node->sum = node->left->sum + node->right->sum;
}
