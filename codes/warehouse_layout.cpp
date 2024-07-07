// Warehouse Layout Optimization
// Using KD Tree
// Assumes Point struct with x, y coordinates
Node* buildKdTree(vector<Point>& points, int depth = 0) {
    if (points.empty()) return nullptr;
    int axis = depth % 2;
    sort(points.begin(), points.end(), [axis](const Point& a, const Point& b) {
        return axis == 0 ? a.x < b.x : a.y < b.y;
    });
    int mid = points.size() / 2;
    Node* node = new Node(points[mid]);
    node->left = buildKdTree(vector<Point>(points.begin(), points.begin() + mid), depth + 1);
    node->right = buildKdTree(vector<Point>(points.begin() + mid + 1, points.end()), depth + 1);
    return node;
}
