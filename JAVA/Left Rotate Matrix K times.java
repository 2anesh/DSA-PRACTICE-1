class Solution {
    int[][] rotateMatrix(int k, int mat[][]) {
        int n = mat.length;
        int m = mat[0].length;
        int mat2[][] = new int[n][m];
        k = k % m;
        for(int i = 0; i < m; i++)
        {
            int j = 0;
            if(i >= k)
            {
                j = i - k;
            }
            else
            {
                int a = k - i;
                j = m - a;
            }
            for(int b = 0; b < n; b++)
            {
                mat2[b][j] = mat[b][i];
            }
        }
        return mat2;
    }
}
