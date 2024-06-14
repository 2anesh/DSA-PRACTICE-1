class Solution {
    public int minIncrementForUnique(int[] nums) {        
        if (nums.length == 1) return 0;
        int max = 0;
        for (int val : nums) {
            max = Math.max(max, val);
        }        
        int count = 0;
        int[] freq = new int[max + nums.length];
        for (int i=0; i<nums.length; i++) {
            freq[nums[i]] += 1;
        }
        for (int i=0; i<freq.length; i++) {
            if (freq[i] <= 1) continue;

            int d = freq[i] - 1;
            freq[i + 1] += d;
            count += d;    
        }
        return count;
    }
}
