class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k = -1;k<=1;k++){
            int a = i+k;
            int b = j+1;
            if(a>=grid.size() || a<0 || b>=grid[0].size()) continue;
            if(grid[i][j]<grid[a][b]){
                ans = max(ans,1+rec(a,b,grid,dp));
            }
        }
        return dp[i][j]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
           ans = max(ans,rec(i,0,grid,dp));
        }
        return ans;
    }
};
