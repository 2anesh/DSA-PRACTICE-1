class Solution
{
    public:
        int solve(string& a, string& b, string& c, int i, int j, int k, vector<vector<vector<int>>>& dp){
            if(i>=a.length() || j>=b.length() || k>=c.length())return 0;
            if(dp[i][j][k]!=-1)return dp[i][j][k];
            if(a[i]==b[j] && a[i]==c[k] && b[j]==c[k])return 1+solve(a,b,c,i+1,j+1,k+1,dp);
            return dp[i][j][k]=max(solve(a,b,c,i+1,j,k,dp), max(solve(a,b,c,i,j+1,k,dp),solve(a,b,c,i,j,k+1,dp)));
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1,-1)));
            int i=0;
            int j=0;
            int k=0;
            return solve(A,B,C,0,0,0,dp);
            
        }
};
