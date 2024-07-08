
//  while studying about the algorithms , interestingly in found out that k means clustering is one of the 
// simple algos to implement and it is not limited to the ML as i presumed.
// Using K-Means Clustering here best optimise my chance to find out all the  similar returns  that i can
//ship back  using few common attributes  
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
