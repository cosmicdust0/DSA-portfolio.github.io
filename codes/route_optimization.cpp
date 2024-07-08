// when i learnt A* i found it interesting and made sure that Ill use in at least one business case and here
// in the Route Optimization module i have used it 

// ill assume a  Node struct   with x, y , g , h,  f, parent

struct Node {
  int x, y;
     double g, h, f;
  Node* parent;
    
     Node(int x = 0, int y = 0) : x(x), y(y), g(0), h(0), f(0), parent(nullptr) {}S
    
    bool operator<(const Node& other) const {
            return f > other.f;  // For priority queue to be min-heap
    }
    
     bool operator==(const Node& other) const {
         return x == other.x && y == other.y;
    }
};


struct NodeHash {
    size_t operator()(const Node& node) const {
        return hash<int>()(node.x) ^ hash<int>()(node.y);
    }
};

double heuristic(const  Node&  a, const Node& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<Node> getNeighbors(const Node& node, const vector<vector<int>>& grid) {
    vector<Node> neighbors;
     vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    for (const auto& dir : directions) {
        int newX = node.x + dir.first;
         int newY = node.y + dir.second;
        
         if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 0) {
           neighbors.emplace_back(newX, newY);
        }
    }
    
     return  neighbors;
}

vector<Node> buildPath(Node* node) {
    vector<Node> path;
     while (node != nullptr) {
          path.push_back(*node);
        node = node->parent;
    }
      reverse(path.begin(), path.end());
     return path;
}

vector<Node> aStar(Node s, Node e) {
    priority_queue<Node> q;
     q.push(s);
     while (!q.empty()) {
        Node c = q.top(); q.pop();
          if (c.x == e.x && c.y == e.y) return buildPath(c);
        for (Node n : getNeighbors(c)) {
            n.g = c.g + 1;
             n.h = heuristic(n, e);
            n.f = n.g + n.h;
             n.parent = &c;
            q.push(n);
        }
    }
    return {};
}
