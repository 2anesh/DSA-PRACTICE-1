class Solution {
    int findMaxSum(int n, int m, int mat[][]) {
        int R = mat.length, C = mat[0].length, res = -1;
        for (int i = 0, cur = 0; i <= R - 3; i++, cur = 0) {
            for (int j = 0; j <= C - 3; j++) {
                cur = mat[i][j] + mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + 1] + mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];
                res = Math.max(res, cur);
            }
        }
        return res;
    }
};
