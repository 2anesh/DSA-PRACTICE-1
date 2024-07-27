class Solution{
    static int n;
    static int dp[][];
    static int countMin(String str)
    {
        n=str.length();
        dp=new int[n+1][n+1];
        for(int d[]:dp)Arrays.fill(d,-1);
        return solve(str,0,n-1);
    }
    static int solve(String s,int i,int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s.charAt(i)==s.charAt(j)){
            return dp[i][j]= solve(s,i+1,j-1);
        }
        int left=1+solve(s,i,j-1);
        int right=1+solve(s,i+1,j);
        return dp[i][j]= Math.min(left,right);
    }
}
