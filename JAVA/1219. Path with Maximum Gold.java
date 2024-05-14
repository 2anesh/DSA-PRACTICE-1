class Solution {
    boolean[][] visited;
    int max = 0;
    int pot=0;
    public int getMaximumGold(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        visited = new boolean[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    func(i,j,grid,n,m);
                }
            }
        }
        return max;
    }
    public void func(int i,int j,int[][] grid,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 ||visited[i][j]==true ){
            return;
        }
        visited[i][j]=true;
        pot+=grid[i][j];
        func(i+1,j,grid,n,m);
        func(i,j+1,grid,n,m);
        func(i-1,j,grid,n,m);
        func(i,j-1,grid,n,m);        
        if(pot>max){
            max=pot;
        }
        visited[i][j]=false; 
        pot-=grid[i][j];
    }
}
