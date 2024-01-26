class Solution {
   public:                  
	int mod = 1e9+7;          
	int di[4] = {0,1,0,-1};      
	int dj[4] = {1,0,-1,0};
       int Totpath(vector<vector<vector<int>>> &dp,int m, int n, int maxMove,int i,int j){
    if(i >= m || j >= n || i<0 || j<0) return 1;
    if(maxMove <= 0) return 0;
    if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove]; 
   int ans = 0; 
   for(int k = 0; k < 4; k++){
   ans = (ans+Totpath(dp,m,n,maxMove-1,i+di[k],j+dj[k]))%mod; 
   }
  return dp[i][j][maxMove] = ans;     
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
   vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));    
    return Totpath(dp, m, n, maxMove,startRow,startColumn)%mod;        
}
};
