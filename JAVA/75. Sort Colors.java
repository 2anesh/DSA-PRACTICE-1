class Solution {
    public void sortColors(int[] nums) {
        int n=0;
        int i=0;
        while(n<2)
        {
           for(int j=i;j<nums.length;j++)
           {
               if(nums[j]==n)
               {
                nums[j]=nums[i];
                nums[i]=n;
                i++;
               }
           }
           n++;
        }
        
    }
}
