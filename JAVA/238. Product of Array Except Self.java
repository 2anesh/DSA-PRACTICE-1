class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans= new int[nums.length];
        int product=1;
        int pwZero=0;
        for(int i=0;i<nums.length;i++)
        {
           if(nums[i]!=0) 
            product=product*nums[i];
           else
            pwZero++;
        }

        for(int j=0;j<nums.length;j++)
        {
         if(pwZero==1)
         {
             if(nums[j]!=0)
             {
                 ans[j]=0;
             }
             else{
                 ans[j]=product;
             }
         }
         else if(pwZero>1)
         {
             ans[j]=0;
         } 
         else{
             ans[j]=product/nums[j];
         }         
        }
        return ans;
    }
}
