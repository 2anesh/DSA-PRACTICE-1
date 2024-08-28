class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size(); 
        if ((n-1) % (k-1)) return -1; 
        vector<int> prefix(1, 0); 
        for (auto& x : stones) prefix.push_back(prefix.back() + x); 
        vector<vector<int>> dp(n, vector<int>(n+1)); 
        for (int lo = n-k; lo >= 0; --lo) 
            for (int hi = lo+k; hi <= n; ++hi) {
                dp[lo][hi] = INT_MAX; 
                for (int mid = lo+1; mid < hi; mid += k-1) 
                    dp[lo][hi] = min(dp[lo][hi], dp[lo][mid] + dp[mid][hi]); 
                if ((hi-lo-1) % (k-1) == 0) dp[lo][hi] += prefix[hi] - prefix[lo]; 
            }
        return dp[0].back(); 
    }
};
