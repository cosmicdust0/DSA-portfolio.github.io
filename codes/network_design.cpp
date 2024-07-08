//  for the netword design i found that Boruvka's Algorithm will best suit here is the 
// sample implementation of it  
//  
vector< pair<int, int >>boruvka( vector< vector<pair<int , int>>>& graph) {
    int n = graph.size();
    vector<int> parent(n);
    vector<pair<int, int>> mst;
    
    for (int i = 0; i < n; i++) parent[i] = i;
    bool done = false;
    while (!done) 
    {

    done = true;
      vector<pair<int, pair<int, int>>> cheapest(n, {INT_MAX, {-1, -1}});
     for (int i = 0; i < n; i++) {
        for (auto& edge : graph[i]) {
                int to = edge.first, weight = edge.second;
                int set1 = find(parent, i), set2 = find(parent, to);
                if (set1 != set2 && weight < cheapest[set1].first)
                    cheapest[set1] = {weight, {i, to}};
            }
        }
        for (int i = 0; i < n; i++) {
            if (cheapest[i].second.first != -1) {
                int set1 = find(parent, cheapest[i].second.first);
                int set2 = find(parent, cheapest[i].second.second);
                if (set1 != set2) {
                    mst.push_back(cheapest[i].second);
                    parent[set1] = set2;
                    done = false;
                }
            }
        }
    }
    return mst;
}
