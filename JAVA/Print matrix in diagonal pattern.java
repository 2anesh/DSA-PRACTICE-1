class Solution {
    public int[] matrixDiagonally(int[][] mat) {
        
        int n = mat.length;
        int ans[] = new int[n*n];
        int ind = 0;
        boolean up = true;
        
        int row = 0 , col = 0;
        
        while(row < n && col < n){
            
            if(up){
                while(row > 0 && col < n-1 ){
                    ans[ind++] = mat[row][col];
                    row--;
                    col++;
                }
                    ans[ind++] = mat[row][col];
                    if(col == n-1){
                        row++;
                    }
                    else{
                        col++;
                    }
                
            }else{
                
                while(row < n-1 && col > 0){
                    ans[ind++] = mat[row][col];
                    row++;
                    col--;
                    
                }
                    ans[ind++] = mat[row][col];
                    if(row == n-1){
                        col++;
                    }
                    else{
                        row++;
                    }
            }
            up = !up;
        }
        
        return ans;
        
    }
}
