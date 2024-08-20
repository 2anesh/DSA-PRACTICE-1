class Solution {
    public int solve(int [] piles,int i,int trn,int m,int [][][]dp)
    {
        int n=piles.length;
        if(i>=n)
            return 0;
        if(dp[trn][i][m]!=0)
            return dp[trn][i][m];
        int res=trn==1?Integer.MAX_VALUE:Integer.MIN_VALUE;
        int scr=0;
        for(int x=1;x<=Math.min(2*m,n-i);x++)
        {
            scr+=piles[i+x-1];
            if(trn==0)
                res=Math.max(res,scr+solve(piles,i+x,1,Math.max(m,x),dp));
            else                 
                res=Math.min(res,solve(piles,i+x,0,Math.max(m,x),dp));        
        }
        return dp[trn][i][m]=res;
    }
    public int stoneGameII(int[] piles) {
        int [][][]dp=new int[2][piles.length+1][piles.length+1];
        return solve(piles,0,0,1,dp);
    }
}
