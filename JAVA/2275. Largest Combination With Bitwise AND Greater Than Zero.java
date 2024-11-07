class Solution {
    public int largestCombination(int[] candidates) {
        int maxCombinationSize = 0;
        for (int bit = 0; bit < 24; bit++) {
            int count = 0;
            for (int num : candidates) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }
            maxCombinationSize = Math.max(maxCombinationSize, count);
        }
        
        return maxCombinationSize;
    }
}
