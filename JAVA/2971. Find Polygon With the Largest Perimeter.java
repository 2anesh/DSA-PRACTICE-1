class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);        
        long previous_elements_sum = 0;
        long ans = -1;
        for (int num : nums) {
            if (num < previous_elements_sum) {
                ans = Math.max(ans, previous_elements_sum + num);
            }
            previous_elements_sum += num;
        }
        return ans;
    }
}
