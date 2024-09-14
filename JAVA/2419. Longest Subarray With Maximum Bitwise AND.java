class Solution {
    public int longestSubarray(int[] nums) {
        int maxElement = 0;
        int maxLength = 0;
        int currentLength = 0;
        for(int num :nums) {
            if(num > maxElement) {
                maxElement = num;
                currentLength = 1;
                maxLength = 1;
            } else if(num == maxElement) {
                currentLength++;
                maxLength = Math.max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }
        return maxLength;
    }
}
