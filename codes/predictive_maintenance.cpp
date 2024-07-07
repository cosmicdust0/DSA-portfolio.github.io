// Predictive Maintenance System
// Using Random Forest (simplified)
// Assumes DecisionTree struct
vector<DecisionTree> buildForest(vector<vector<int>>& data, int numTrees) {
    vector<DecisionTree> forest;
    for (int i = 0; i < numTrees; i++) {
        vector<vector<int>> sample = bootstrapSample(data);
        forest.push_back(buildDecisionTree(sample));
    }
    return forest;
}
