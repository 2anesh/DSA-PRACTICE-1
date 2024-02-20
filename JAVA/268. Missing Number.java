class Solution {
    public int missingNumber(int[] nums) {
        int i=0;
        while(i<nums.length){
            int correct=nums[i]; //small change from cycle sort
            if(nums[i]!=nums.length && nums[i]!=nums[correct]){
                int t = nums[i];
                nums[i] = nums[correct];
                nums[correct] = t;
            }
            else{
                i++;
            }
        }
        i=0; 
        while(i<nums.length){
            if(nums[i]!=i)
            return i;
            i++;
        }
        return nums.length;
    }
}
