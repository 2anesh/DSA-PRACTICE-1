class Solution {
public:
    int checkRecord(int n) {
        vector<long> dp = {1, 2, 4}; 
        for (int i = 3; i <= n; ++i) 
            dp.push_back((dp[i-3] + dp[i-2] + dp[i-1]) % 1'000'000'007);
        int ans = dp[n]; 
        for (int i = 0; i < n; ++i) 
            ans = (ans + dp[i] * dp[n-1-i]) % 1'000'000'007; 
        return ans; 
    }
};
