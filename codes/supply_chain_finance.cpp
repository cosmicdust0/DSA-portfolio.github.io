
// Supply Chain Finance Optimization
// Using Network Flow (Edmonds-Karp Algorithm)
int edmondsKarp(vector<vector<int>>& capacity, int source, int sink) {
    int n = capacity.size(), maxFlow = 0;
    vector<vector<int>> flow(n, vector<int>(n, 0));
    while (true) {
        vector<int> parent(n, -1);
        queue<pair<int, int>> q;
        q.push({source, INT_MAX});
        parent[source] = source;
        while (!q.empty() && parent[sink] == -1) {
            int u = q.front().first, f = q.front().second;
            q.pop();
            for (int v = 0; v < n; v++) {
                if (parent[v] == -1 && capacity[u][v] > flow[u][v]) {
                    parent[v] = u;
                    int new_f = min(f, capacity[u][v] - flow[u][v]);
                    if (v == sink) {
                        maxFlow += new_f;
                        int cur = sink;
                        while (cur != source) {
                            int prev = parent[cur];
                            flow[prev][cur] += new_f;
                            flow[cur][prev] -= new_f;
                            cur = prev;
                        }
                        break;
                    }
                    q.push({v, new_f});
                }
            }
        }
        if (parent[sink] == -1) break;
    }
    return maxFlow;
}