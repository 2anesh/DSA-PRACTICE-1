class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        int k = *max_element(a.begin(),a.end());
        int maxi=-1;
        vector<int>dp(k+2,0);
        for(int x:a){
        dp[x] = max(dp[x-1],dp[x+1])+1; 
        maxi = max(maxi,dp[x]);
        }
        return maxi;
    }
};
