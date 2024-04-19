class Solution {
        public int numIslands(char[][] grid) {
            int h = grid.length;   
            if (h == 0) return 0;  
            int l = grid[0].length; 
            int result = 0;
            for (int i = 0; i < h; i++) {  //loop iterates over rows
                for (int j = 0; j < l; j++) {
                    if (grid[i][j]=='1'){
                        dfs(grid, i, j);
                        result++;
                    }
                }
            }
            return result;
        }
        public void dfs(char[][] grid, int row, int col){
            int H = grid.length;
            int L = grid[0].length;
            if (row < 0 || col < 0 || row >= H || col >= L || grid[row][col] != '1'){
                return;
            }
            grid[row][col]='0';  
            dfs(grid, row+1, col); 
            dfs(grid, row-1, col);  
            dfs(grid, row, col+1);  
            dfs(grid, row, col-1);  
        }
}
