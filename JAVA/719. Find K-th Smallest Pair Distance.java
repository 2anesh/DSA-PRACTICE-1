class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int left = 0;
        int right = nums[nums.length - 1] - nums[0];        
        while (left < right) {
            int mid = (left + right) / 2;
            int count = countPairsWithDistanceLessThanOrEqualTo(nums, mid);
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }       
        return left;
    }   
    private int countPairsWithDistanceLessThanOrEqualTo(int[] nums, int maxDistance) {
        int count = 0;
        int j = 0;
        
        for (int i = 0; i < nums.length; i++) {
            while (j < nums.length && nums[j] - nums[i] <= maxDistance) {
                j++;
            }
            count += j - i - 1;
        }       
        return count;
    }
}
