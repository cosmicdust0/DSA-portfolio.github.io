// I have  implemented a simplified version of the NSGA-II algorithm
vector<Solution> nsga2(vector<Solution>& population) {
    //  first i will sort the population into non-dominated fronts
 vector<vector<Solution>> fronts = fastNonDominatedSort(population);
    
     vector<Solution> newPopulation;
    
    //  then i will fill the new population with solutions from each front
    for (auto& front : fronts) {
        // If we can add the entire front, do so
         if (newPopulation.size() + front.size() <= population.size()) {
            newPopulation.insert(newPopulation.end(), front.begin(), front.end());
        }else {
            // If adding the entire front would exceed the population size then i will :
            // 1. Calculate crowding distance for this front
            // 2. Sort the front based on crowding distance
            // 3. Add only as many solutions as needed to fill the population
            crowdingDistanceAssignment(front);
            sort(front.begin(), front.end(), crowdingComparator);
          newPopulation.insert(newPopulation.end(), front.begin(), front.begin() + (population.size() - newPopulation.size()));
            break;
        }
    }
    
    // Return the new population
    return newPopulation;
}
