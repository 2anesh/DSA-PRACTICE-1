class Solution {
  public:
    int solve(int i, int j , string & a, string & b,vector<vector<int>> & dp){
        
        if (i>=a.size()){
            return b.size()-j;
        }
        if (j>=b.size()){
            return a.size()-i;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int equal = 0, dlt = 0, Insert = 0 , Replace_char_from_string_b = 0;
        if (a[i]==b[j]){
            equal = solve(i+1,j+1,a,b,dp);
            return dp[i][j] = equal;
        }
        else{
            dlt =1 + solve(i+1,j, a,b,dp);
            Insert = 1 + solve(i,j+1,a,b,dp);//assuming we inserted an correct charecter
            Replace_char_from_string_b = 1 + solve(i+1,j+1,a,b,dp);
        }
        return dp[i][j] = min(dlt,min(Insert,Replace_char_from_string_b));
    }
    int editDistance(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,dp);
    }
};
