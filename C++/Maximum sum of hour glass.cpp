class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        if(n <= 2 || m <= 2) return -1;
        int res = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                int sum = mat[i-1][j-1] + mat[i-1][j] + mat[i-1][j+1] 
                          + mat[i][j]                                 
                          + mat[i+1][j-1] + mat[i+1][j] + mat[i+1][j+1];
                res = max(res,sum);
            }
        }
        return res; 
    }
};
