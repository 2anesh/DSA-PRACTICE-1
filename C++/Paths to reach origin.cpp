class Solution
{
public:
    int dp[501][501];
       int f(int x, int y) {
        if(x < 0 or y < 0) return 0;
        if(!x and !y) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = (f(x - 1, y) + f(x, y - 1)) % 1000000007;
        }
       int ways(int x, int y) {
        memset(dp, -1, sizeof dp);
        return f(x, y);
      }
};
