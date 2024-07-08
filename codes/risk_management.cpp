// i found out that DFS will be the best and simple traversal to use in the case hence here is the base code for it 
// i have implemented the recusion version fo DFS
void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) 
        dfs(u, adj, visited); //recursion 
    }
}
