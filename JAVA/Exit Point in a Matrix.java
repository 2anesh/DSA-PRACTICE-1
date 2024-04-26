class Solution {
    private boolean isValid(int[][] matrix, int i, int j) {
        if (i<0 || j <0 || i >= matrix.length || j >= matrix[0].length) return false;
        return true;
    }
    public int[] FindExitPoint(int n, int m, int[][] matrix) {
        int cur = 0;
        int[] ans = new int[2]; 
        int[][] dir = {{0,1}, {1, 0}, {0,-1}, {-1, 0}};
        int i = 0 , j = 0 ;
        while(isValid(matrix, i, j)) {
            if (matrix[i][j] == 1) {
                cur = (cur+1)%4;
                matrix[i][j] = 0;
            }
            i = i + dir[cur][0];
            j = j + dir[cur][1]; 
        }
        return new int[]{i-dir[cur][0], j-dir[cur][1] };
    }
}
