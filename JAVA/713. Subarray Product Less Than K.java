class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if(k == 0) return 0;
        int res = 0;
        int product = 1;
        int l = 0;
        for(int r = 0; r < nums.length; r++) {
            if(nums[r] >= k) {
                l = r + 1;
                product = 1;
                continue;
            }
            product *= nums[r];
            while (product >= k) {
                product /= nums[l++];
            }
            res += r - l + 1;
        }
        return res;
    }
}
