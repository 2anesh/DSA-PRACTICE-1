class Solution {
    public int findMaxK(int[] nums) {
      int ans=-1;
      for(int i=0;i<nums.length-1;i++){
        for(int j=i+1;j<nums.length;j++){
           if((nums[i]<0)&&(Math.abs(nums[i])==Math.abs(nums[j]))){
            ans=Math.max(ans,nums[j]);
           }
           if(nums[j]<0&&Math.abs(nums[i])==Math.abs(nums[j])){
            ans=Math.max(ans,nums[i]);
           }
        }
      }  
      return ans;
    }
}
