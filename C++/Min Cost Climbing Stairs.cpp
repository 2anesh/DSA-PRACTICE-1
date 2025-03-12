class Solution {
  public:
  
    int solve(int i , int n , vector<int>&cost , vector<int>&dp){
        if(i >= n) return 0 ; 
        if(dp[i] != -1) return dp[i] ; 
        return dp[i] = cost[i] + min(solve(i+1,n,cost,dp),
        solve(i+2,n,cost,dp)) ; 
    }
  
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size() ; 
        vector<int>dp(n,-1) ; 
        return min(solve(0,n,cost,dp),solve(1,n,cost,dp)) ; 
    }
};
