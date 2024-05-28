class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= w; i++) {
            for(int j = 0; j < n; j++) {
                if(cost[j] != -1 && (i - j - 1) >= 0) {
                    dp[i] = min(dp[i], cost[j] + dp[i - j - 1]);
                }
            }
        }
        return dp[w];
    }
};
