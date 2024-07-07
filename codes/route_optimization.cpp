// Inventory Optimization System
// Using Fenwick Tree (Binary Indexed Tree)
vector<int> ft;
void upd(int i, int v) {
    for (; i < ft.size(); i += i & -i) ft[i] += v;
}
int qry(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += ft[i];
    return s;
}