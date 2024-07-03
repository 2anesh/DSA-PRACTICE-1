class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        int result = Integer.MAX_VALUE;
        if (n <= 4) return 0;
        Arrays.sort(nums);
        for (int i = n - 4; i < n; i++){
            result = Math.min(result, nums[i] - nums[i - n + 4]);
        }
        return result;
    }
}
