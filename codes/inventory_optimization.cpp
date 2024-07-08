
// for Inventory Optimization Systems when i researched for a structure that is being already used i found out that
// the Fenwick Tree is the best option for this case
//  i have mentioned the Fenwick Tree base code for update and query 

vector<int> ft;
void upd(int i, int v) {
    for (; i < ft.size(); i += i & -i) ft[i] += v;
}
int qry(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += ft[i];
    return s;
}