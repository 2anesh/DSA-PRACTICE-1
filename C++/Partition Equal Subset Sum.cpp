class Solution {
  public:
  
    bool solve(int ind,vector<int>& arr,int sum,vector<vector<int>>& dp){
        
        if(ind==0){
            
            if(sum - arr[ind] ==0){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(ind<0 || sum <0){
            return false;
        }
        
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        
        int take = solve(ind-1,arr,sum-arr[ind],dp);
        int nottake = solve(ind-1,arr,sum,dp);
        
        return dp[ind][sum] =  take || nottake;
        
        
    }
  
    bool equalPartition(vector<int>& arr) {
        int sum=0;
        for(int i:arr){
            sum+= i;
        }
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (sum/2 + 1,-1));
        return (sum%2 == 0) ? solve(n-1,arr,sum/2,dp) : false;
    }
};
