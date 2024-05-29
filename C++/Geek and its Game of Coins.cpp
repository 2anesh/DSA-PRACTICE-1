class Solution {
  public:
    int wins(int n, int x, int y, vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        int condition1 = (!(wins(n-1, x, y, dp)));
        int condition2 = 0, condition3 = 0;
        if(n-x >= 0) condition2 = (!(wins(n-x, x, y, dp)));
        if(n-y >= 0) condition3 = (!(wins(n-y, x, y, dp)));
        return dp[n] = condition1 | condition2 | condition3;
    }
    int findWinner(int n, int x, int y) {
        vector<int> dp(n+1, -1);
        return wins(n, x, y, dp);
     }
};
