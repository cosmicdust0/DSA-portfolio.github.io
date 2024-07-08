
//  for dynamic pricing optimization ill be using
// reinforcement learning algo (Q-learning) i have tried to simplify this 
// which is basically a dp sloution when i will loop it in the main function 
void qLearning(vector<vector<double>>& Q, int s, int a, double r, int s_next) {
    double alpha = 0.1, gamma = 0.9;
    double best_q = *max_element(Q[s_next].begin(), Q[s_next].end());
    Q[s][a] += alpha * (r + gamma * best_q - Q[s][a]);
}