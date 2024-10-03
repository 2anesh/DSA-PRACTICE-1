class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        long totalSum = 0;        
        for (int num : nums) {
            totalSum += num;
        }        
        long remainder = totalSum % p;
        if (remainder == 0) return 0;
        HashMap<Long, Integer> prefixMap = new HashMap<>();
        prefixMap.put(0L, -1);  
        long prefixSum = 0;
        int minLength = n;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            long mod = prefixSum % p;
            long targetMod = (mod - remainder + p) % p;           
            if (prefixMap.containsKey(targetMod)) {
                minLength = Math.min(minLength, i - prefixMap.get(targetMod));
            }           
            prefixMap.put(mod, i);
        }
        return minLength == n ? -1 : minLength;
    }
}
