class Solution {
public:
    int mod=1e9+7;
    long long int ans=INT_MIN, m, n;    
    void dfs(vector<vector<int>>&grid, int i, int j, long long int prod){
        if(!grid[i][j]) {
            long long int k=0;
            ans=max(ans, k);
            return;
        }        
        prod*=grid[i][j];
        if(i==m-1 && j==n-1){
            ans=max(ans, prod);
            return;
        }        
        if(i+1<m) dfs(grid, i+1, j, prod);
        if(j+1<n) dfs(grid, i, j+1, prod);        
    }    
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        dfs(grid, 0, 0, 1);        
        if(ans<0) return -1;
        return ans%mod;
    }
};
