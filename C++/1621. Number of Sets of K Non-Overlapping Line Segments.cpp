class Solution {
public:
    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(n, vector<int>(K + 1));
        int kMod = 1e9 + 7;        
        dp[1][1] = 1;        
        for (int i = 2; i < n; i++)
            dp[i][1] = (i + 1) * i / 2;        
        vector<vector<int>> sum(n, vector<int>(K + 1));       
        for (int i = 2; i < n; i++) {
            for (int k = 2; k <= K; k++) {
                if (k <= i)
                    sum[i][k] =  (sum[i - 1][k] + dp[i - 1][k - 1]) % kMod;
                dp[i][k] = (sum[i][k] + dp[i - 1][k]) % kMod;         
            }
        }        
        return dp[n - 1][K];
    }
};
