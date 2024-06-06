#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>

// Supplier data structure
struct Supplier {
  // Replace with your actual data members for supplier information
  std::string name;
  std::string address;
  std::string phone;
  std::string email;
  // ... product catalog, lead time, etc.
  int id;
};

// Hash table to store suppliers
std::unordered_map<int, Supplier> suppliers;

// Add supplier (assuming data is populated elsewhere)
void addSupplier(const Supplier& supplier) {
  suppliers[supplier.id] = supplier;
}

// Get supplier information by ID
Supplier getSupplier(int id) {
  if (suppliers.count(id)) {
    return suppliers[id];
  } else {
    // Handle supplier not found (e.g., throw exception, return default values)
    Supplier emptySupplier;
    emptySupplier.name = "Not Found";
    // ... set other fields to indicate not found
    return emptySupplier;
  }
}

// Node structure for A* search
struct Node {
  int id; // Supplier location ID
  double g; // Distance traveled to reach this node
  double f; // Total cost (g + h)
  int parent; // Parent node in the path

  Node(int id, double g, double h, int parent = -1) :
      id(id), g(g), f(g + h), parent(parent) {}

  // Overloading comparison for priority queue (lower f gets priority)
  bool operator>(const Node& other) const {
    return f > other.f;
  }
};

// Heuristic function (replace with your specific logic)
double heuristic(int from, int to) {
  // Use supplier_locations to access supplier coordinates
  // Supplier location data structure (replace with your actual implementation)
std::unordered_map<int, std::vector<double>> supplier_locations;

  const std::vector<double>& from_location = supplier_locations[from];
  const std::vector<double>& to_location = supplier_locations[to];

  // Assuming locations are stored as x, y coordinates
  if (from_location.size() != 2 || to_location.size() != 2) {
    // Handle invalid location data format
    return 0.0; // Or throw an exception
  }

  return sqrt(pow(from_location[0] - to_location[0], 2) + pow(from_location[1] - to_location[1], 2));
}

// A* Search Algorithm
std::vector<int> AStarSearch(int start, int goal, const std::vector<std::vector<double>>& graph) {
  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
  std::unordered_set<int> closed;

  pq.push(Node(start, 0, heuristic(start, goal)));

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();

    if (closed.count(current.id)) continue;
    closed.insert(current.id);

    if (current.id == goal) {
      // Reconstruct path by traversing parents
      std::vector<int> path;
      int node = current.id;
      while (node != -1) {
        path.push_back(node);
        node = graph[node][current.parent]; // Access parent from graph data
      }
      std::reverse(path.begin(), path.end()); // Reverse for start -> goal order
      return path;
    }

    for (int neighbor = 0; neighbor < graph[current.id].size(); neighbor++) {
      if (closed.count(neighbor)) continue;
      double tentative_g = current.g + graph[current.id][neighbor];
      bool new_path = false;
      if (!pq.empty() && tentative_g >= pq.top().g) continue; // Already explored better path
      if (!pq.empty() && pq.top().id == neighbor) {
        new_path = tentative_g < pq.top().g;
      } else {
        new_path = true;
      }
      if (new_path) {
        pq.push(Node(neighbor, tentative_g, heuristic(neighbor, goal), current.id));
      }
    }
  }

