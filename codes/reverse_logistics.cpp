

// Reverse Logistics Optimization
// Using K-Means Clustering
vector<Point> kMeans(vector<Point>& points, int k) {
    vector<Point> centroids = initializeCentroids(points, k);
    vector<int> assignments(points.size());
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < points.size(); i++) {
            int closest = findClosestCentroid(points[i], centroids);
            if (closest != assignments[i]) {
                assignments[i] = closest;
                changed = true;
            }
        }
        updateCentroids(points, assignments, centroids);
    }
    return centroids;
}
