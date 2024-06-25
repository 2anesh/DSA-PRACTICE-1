class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, INT_MAX)); 
        for (int i = 0; i <= n; ++i) dp[i][0] = i; 
        dp[0][0] = dp[0][1] = 0;         
        for (int i = 1; i <= n; ++i) 
            for (int ii = 1; ii <= i; ++ii) 
                dp[i][1] = min(dp[i][1], 1 + max(dp[ii-1][0], dp[i-ii][1])); 
        return dp[n][1]; 
    }
};
