class Solution {
  public:
    int solve(int k, vector<int>& arr,int start,int end,vector<int>&dp){
        if(start==end)return 0;
        if(start>end)return 1e5;
        if(dp[start]!=1e5)return dp[start];
        int ans1=1e5;
        for(int i=1;i<=k;i++){
            int ans2= solve(k,arr,start+i,end,dp)+abs(arr[start]-arr[start+i]);
            ans1=min(ans1,ans2);
        }
        dp[start]=min(dp[start],ans1);
        return dp[start];
    }
    int minimizeCost(int k, vector<int>& arr) {
        vector<int>dp(arr.size()+1,1e5);
        return solve(k,arr,0,arr.size()-1,dp);
    }
};
