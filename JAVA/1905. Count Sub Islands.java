class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int n = grid1.length;
        int m = grid1[0].length;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                   boolean call = dfs(grid1,grid2,i,j,n,m);
                    if(call){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    public boolean dfs(int[][] b1,int[][] b2,int i,int j,int n,int m){     
        if(i<0 || j<0 || i>=n || j>=m || b2[i][j]==0){
            return true;
        }
          if(b2[i][j]==1 && b1[i][j]==0) return false;
        b2[i][j]=0;
        boolean c1 = dfs(b1,b2,i+1,j,n,m);
        boolean c2 = dfs(b1,b2,i-1,j,n,m);
        boolean c3 = dfs(b1,b2,i,j+1,n,m);
        boolean c4 = dfs(b1,b2,i,j-1,n,m);
        return c1 && c2 && c3 && c4;
    }
}
