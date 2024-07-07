// Smart Contract Management System
// Using Merkle Trees
string getMerkleRoot(vector<string>& transactions) {
    if (transactions.empty()) return "";
    vector<string> tree = transactions;
    while (tree.size() > 1) {
        vector<string> newLevel;
        for (int i = 0; i < tree.size(); i += 2) {
            string left = tree[i];
            string right = (i + 1 < tree.size()) ? tree[i + 1] : left;
            newLevel.push_back(hash(left + right));
        }
        tree = newLevel;
    }
    return tree[0];
}
