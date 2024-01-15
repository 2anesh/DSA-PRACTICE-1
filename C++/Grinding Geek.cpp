class Solution{
    public:
    int solve(int y,int total,vector<int>&cost,int i,vector<vector<int>>&dp){
        if(i==y){
            return 0;
        }
        else if(total==0){
            return 0;
        }
        if(dp[i][total]!=-1){
            return dp[i][total];
        }
        if(total >= cost[i]){
            return dp[i][total] = max(solve(y,total,cost,i+1,dp),1+solve(y,total-cost[i]+floor(0.9*cost[i]),cost,i+1,dp));
        }
        else{
            return dp[i][total] = solve(y,total,cost,i+1,dp);
        }
    }
    int max_courses(int y, int total, vector<int> &cost)
    {
       vector<vector<int>>dp(y+1,vector<int>(total+1,-1));
       return solve(y,total,cost,0,dp);
    }
};
