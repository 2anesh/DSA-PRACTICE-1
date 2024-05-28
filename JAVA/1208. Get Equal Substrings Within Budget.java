class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int[] cost = new int[n];
        for (int i = 0; i < n; i++) {
            cost[i] = Math.abs(s.charAt(i) - t.charAt(i));
        }
        int left = 0, right = 0;
        int currentCost = 0;
        int maxLength = 0;
        while (right < n) {
            currentCost += cost[right];
            while (currentCost > maxCost) {
                currentCost -= cost[left];
                left++;
            }
            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
}
