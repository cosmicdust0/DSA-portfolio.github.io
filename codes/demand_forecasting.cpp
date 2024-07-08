
//  for this module of demand fforecasting system i have  used Segment trees
// SegTree struct will be  left, right, sum
// here is the base update code  
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
