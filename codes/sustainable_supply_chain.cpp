
// Sustainable Supply Chain Management
// Using Multi-Objective Optimization (NSGA-II simplified)
vector<Solution> nsga2(vector<Solution>& population) {
    vector<vector<Solution>> fronts = fastNonDominatedSort(population);
    vector<Solution> newPopulation;
    for (auto& front : fronts) {
        if (newPopulation.size() + front.size() <= population.size()) {
            newPopulation.insert(newPopulation.end(), front.begin(), front.end());
        } else {
            crowdingDistanceAssignment(front);
            sort(front.begin(), front.end(), crowdingComparator);
            newPopulation.insert(newPopulation.end(), front.begin(), front.begin() + (population.size() - newPopulation.size()));
            break;
        }
    }
    return newPopulation;
}
