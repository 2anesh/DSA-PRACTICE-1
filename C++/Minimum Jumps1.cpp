class Solution {
  public:
    
    int dp[10005];
    int solve(int ind , vector<int> &arr){
        if(ind == arr.size()-1) return 0;
        if(ind >=arr.size()) return 1e7;
        
        if(dp[ind] != -1) return dp[ind];
        
        int ans = 1e7;
        
        for(int i = 1 ; i <= arr[ind] ; i++){
            ans = min(ans , 1 + solve(ind + i , arr));
        }
        return dp[ind] = ans;
    }
    int minJumps(vector<int>& arr) {
        memset(dp ,-1, sizeof(dp));
        
        int ans = solve(0 , arr);
        if(ans == 1e7) return -1;
        return ans;
        
        
    }
};
