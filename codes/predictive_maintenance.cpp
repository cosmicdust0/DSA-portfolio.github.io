// this code is refered from another git hub repo and i have modified it 
//  created struct to represent a node in the decision tree
struct Node {
    int feature;
    int threshold;
    int label;
    Node* left;
    Node* right;
    
    Node(int f = -1, int t = -1, int l = -1) : feature(f), threshold(t), label(l), left(nullptr), right(nullptr) {}
};

//  struct to represent a decision tree
struct DecisionTree {
    Node* root;
    DecisionTree() : root(nullptr) {}
};
// all the below code is borrowed and understood 
//  this is the Function to create a bootstrap sample
vector<vector<int>> bootstrapSample(const vector<vector<int>>& data) {
    vector<vector<int>> sample;
    int n = data.size();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n - 1);
    
    for (int i = 0; i < n; i++) {
        sample.push_back(data[dis(gen)]);
    }
    return sample;
}

// Function to calculate Gini impurity
double giniImpurity(const vector<vector<int>>& data) {
    int n = data.size();
    if (n == 0) return 0.0;
    
    vector<int> counts(2, 0);  // Assuming binary classification
    for (const auto& row : data) {
        counts[row.back()]++;
    }
    
    double impurity = 1.0;
    for (int count : counts) {
        double p = static_cast<double>(count) / n;
        impurity -= p * p;
    }
    return impurity;
}

// Function to split the data based on a feature and threshold
pair<vector<vector<int>>, vector<vector<int>>> splitData(const vector<vector<int>>& data, int feature, int threshold) {
    vector<vector<int>> left, right;
    for (const auto& row : data) {
        if (row[feature] <= threshold) {
            left.push_back(row);
        } else {
            right.push_back(row);
        }
    }
    return {left, right};
}

// Function to find the best split
pair<int, int> findBestSplit(const vector<vector<int>>& data) {
    int bestFeature = -1;
    int bestThreshold = -1;
    double bestGini = 1.0;
    
    int nFeatures = data[0].size() - 1;  // Excluding the label column
    for (int feature = 0; feature < nFeatures; feature++) {
        vector<int> values;
        for (const auto& row : data) {
            values.push_back(row[feature]);
        }
        sort(values.begin(), values.end());
        
        for (int i = 0; i < values.size() - 1; i++) {
            int threshold = (values[i] + values[i+1]) / 2;
            auto [left, right] = splitData(data, feature, threshold);
            double gini = (giniImpurity(left) * left.size() + giniImpurity(right) * right.size()) / data.size();
            
            if (gini < bestGini) {
                bestGini = gini;
                bestFeature = feature;
                bestThreshold = threshold;
            }
        }
    }
    
    return {bestFeature, bestThreshold};
}

// Function to build a decision tree
Node* buildTreeRecursive(const vector<vector<int>>& data, int depth, int maxDepth) {
    if (data.empty() || depth >= maxDepth) {
        return new Node();
    }
    
    auto [feature, threshold] = findBestSplit(data);
    if (feature == -1) {
        return new Node();
    }
    
    auto [left, right] = splitData(data, feature, threshold);
    
    Node* node = new Node(feature, threshold);
    node->left = buildTreeRecursive(left, depth + 1, maxDepth);
    node->right = buildTreeRecursive(right, depth + 1, maxDepth);
    
    return node;
}

// Function to build a decision tree
DecisionTree buildDecisionTree(const vector<vector<int>>& data, int maxDepth = 10) {
    DecisionTree tree;
    tree.root = buildTreeRecursive(data, 0, maxDepth);
    return tree;
}

// Function to build the random forest
vector<DecisionTree> buildForest(const vector<vector<int>>& data, int numTrees) {
    vector<DecisionTree> forest;
    for (int i = 0; i < numTrees; i++) {
        vector<vector<int>> sample = bootstrapSample(data);
        forest.push_back(buildDecisionTree(sample));
    }
    return forest;
}

// Function to make a prediction using a single tree
int predict(const Node* node, const vector<int>& sample) {
    if (node->left == nullptr && node->right == nullptr) {
        return node->label;
    }
    
    if (sample[node->feature] <= node->threshold) {
        return predict(node->left, sample);
    } else {
        return predict(node->right, sample);
    }
}

// Function to make a prediction using the random forest
int predictForest(const vector<DecisionTree>& forest, const vector<int>& sample) {
    vector<int> predictions;
    for (const auto& tree : forest) {
        predictions.push_back(predict(tree.root, sample));
    }
    
    // Return the majority vote
    return count(predictions.begin(), predictions.end(), 1) > predictions.size() / 2 ? 1 : 0;
}

