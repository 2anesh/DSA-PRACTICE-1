class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int count = 0, sum = 0;
        Map<Integer, Integer> prefixSumCount = new HashMap<>();
        prefixSumCount.put(0, 1);         
        for (int num : nums) {
            sum += num;            
            if (prefixSumCount.containsKey(sum - goal)) {
                count += prefixSumCount.get(sum - goal);
            }            
            prefixSumCount.put(sum, prefixSumCount.getOrDefault(sum, 0) + 1);
        }       
        return count;
    }
}
