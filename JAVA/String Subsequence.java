class Solution 
{
    static int mod= 1000000007;
    public static int countWays(String s1, String s2) 
    {
        int dp[][]= new int[s1.length()][s2.length()];
        for(int d[]: dp)
        {
            Arrays.fill(d,-1);
        }
        return helper(s1,s2,0,0,dp);
    }
    public static int helper(String a, String b, int x, int y, int[][] dp)
    {
        if(y>=b.length())
        {
            return 1;
        }
        if(x>=a.length())
        {
            return 0;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int take=0;
        if(a.charAt(x)==b.charAt(y))
        {
            take+= (helper(a,b,x+1,y+1,dp))%mod;
        }
        int notake=  (helper(a,b,x+1,y,dp))%mod;
        
        return dp[x][y]= (take+notake)%mod;
    }
}
