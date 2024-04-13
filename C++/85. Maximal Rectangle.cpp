class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxarea=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = (j==0) ? 1 : dp[i][j-1]+1;
                    int width = dp[i][j];
                    for(int height = i;height>=0;height--){
                        width = min(width,dp[height][j]);
                        maxarea = max(maxarea,width*(i-height+1));
                    }
                }
                
            }
        }
        return maxarea;
    }
};
