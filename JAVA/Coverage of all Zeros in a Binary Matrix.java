class Solution {
    public int findCoverage(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j]==0){
                    if(i>0 && matrix[i-1][j]==1){
                        count++;
                    }
                    if(i<n -1 && matrix[i+1][j]==1){
                        count++;
                    }
                    if(j<m-1 && matrix[i][j+1]==1 ){
                        count++;
                    }
                    if(j>0 && matrix[i][j-1]==1){
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
