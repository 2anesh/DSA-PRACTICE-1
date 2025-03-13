class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; i++) {  
            for (int w = W; w >= wt[i]; w--) {  // Traverse in reverse to avoid overwriting
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        return dp[W];  
    }
};
