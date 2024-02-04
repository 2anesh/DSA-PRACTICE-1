import java.util.*;
class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> targetChars = new HashMap<>();
        for (char c : t.toCharArray()) {
            targetChars.put(c, targetChars.getOrDefault(c, 0) + 1);
        }
        int left = 0;
        int minLen = Integer.MAX_VALUE;
        int minStart = 0;
        int remainingChars = t.length();
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s.charAt(right);
            if (targetChars.containsKey(currentChar)) {
                int count = targetChars.get(currentChar);
                if (count > 0) {
                    remainingChars--;
                }
                targetChars.put(currentChar, count - 1);
            }
            while (remainingChars == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char leftChar = s.charAt(left);
                if (targetChars.containsKey(leftChar)) {
                    int count = targetChars.get(leftChar);
                    if (count == 0) {
                        remainingChars++;
                    }
                    targetChars.put(leftChar, count + 1);
                }
                left++;
            }
        }ng
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
}
