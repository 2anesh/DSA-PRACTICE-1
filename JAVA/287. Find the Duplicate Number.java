class Solution {
    public int findDuplicate(int[] nums) {
        int num = -1;
        int length = nums.length;
        Arrays.sort(nums);
        for(int i = 0;i<length-1;i++){
            if(nums[i] == nums[i+1]){
                num = nums[i];
                return num;
            }
        }
        return num;
    }
}
