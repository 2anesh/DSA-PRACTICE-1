class Solution
{   int[][] dp;
    public int min_operations(int []nums)
    {
        dp=new int[nums.length][nums.length];
        for(int[] i: dp)Arrays.fill(i,-1);
       return nums.length - f(0,-1,nums);
        
    }
    int f(int i,int last,int[] nums){
        if(i>=nums.length)return 0;
        if(last!=-1 && dp[i][last]!=-1)return dp[i][last];
        int pick=0;
        if(last==-1 || (i-last<=( nums[i]-nums[last]) &&  nums[last]<nums[i])){
             pick=1+f(i+1,i,nums);
        }
        int nopick=f(i+1,last,nums);
        if(last!=-1)dp[i][last]=Math.max(pick,nopick);
        return Math.max(pick,nopick);
    }
}
