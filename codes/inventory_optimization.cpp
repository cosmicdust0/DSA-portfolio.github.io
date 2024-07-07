// Route Optimization for Last-Mile Delivery
// Using A* Search Algorithm
// Assumes Node struct with x, y, g, h, f, parent
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
