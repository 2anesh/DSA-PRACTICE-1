class Solution {
    public int[] sortedSquares(int[] nums) {
        
        // prepare the ans array
        int[] ans = new int[nums.length];
        
        // use two pointers pointing to the head and tail of the nums array
        int left = 0;
        int right = nums.length - 1;

        int index = nums.length - 1;

        while (left <= right){
            if(nums[left] * nums[left] > nums[right] * nums[right]){
                ans[index--] = nums[left] * nums[left];
                left++;
            }else{
                ans[index--] = nums[right] * nums[right];
                right--;
            }
        }

        return ans;
    }
}
