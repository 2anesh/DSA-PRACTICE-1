class solve
{
    static long countMaximum(int n, int arr[]){
        int[] sum = new int[n+1];
        sum[0] = 0;
        for(int i=0; i<n; i++){
            sum[i+1] = arr[i] + sum[i];
        }
        int[][] dp = new int[n][n];
        for(int i=0; i<n; i++){
            dp[i][i] = arr[i];
        }
        for(int d=1; d<n; d++){
            for(int r=0; r<n-d; r++){
                int c = d+r;
                dp[r][c] = arr[c] + (sum[c] - sum[r]) - dp[r][c-1];
                dp[r][c] = Math.max(dp[r][c], arr[r] + (sum[c+1] - sum[r+1]) - dp[r+1][c]);
            }
        }
        return dp[0][n-1];
    }
}
