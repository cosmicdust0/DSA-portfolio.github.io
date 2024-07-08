// i have impolemented a dp solution for this by refering ti 0/1 knapsack
// here  is the knapsack basecode
vector<int> optInv(vector<int>& demand, int capacity) {
    int n = demand.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
     {
     for (int j = 0; j <= capacity; j++)
         {
         if (j >= demand[i-1])
        {dp[i][j] = max(dp[i-1][j], dp[i-1][j-demand[i-1]] + demand[i-1]);}
            else 
            {
                dp[i][j] = dp[i-1][j];}
        }
    }
    return dp[n];
}
