class Solution {
    static int maxSquare(int n, int m, int mat[][]) {
        int ans = 0;  
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    ans = Math.max(ans, mat[i][j]);
                } else if (mat[i][j] != 0) {
                    mat[i][j] += Math.min(mat[i-1][j], Math.min(mat[i-1][j-1], mat[i][j-1]));
                    ans = Math.max(ans, mat[i][j]);  
                }
            }
        }
        return ans;  
    }
}
