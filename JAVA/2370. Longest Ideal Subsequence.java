class Solution {
    public int longestIdealString(String s, int k) {
        int ans = 1;
        int[] array = new int[26];
        for (int i = 0; i < s.length(); i++) {
            int curr = s.charAt(i) - 'a';
            int currans = 1;
            int temp = k;
            array[curr] += 1;
            int j = curr - 1;
            while (temp > 0) {
                if (j == -1) {
                    break;
                }
                currans = Math.max(currans, array[j] + 1);
                temp--;
                if (j == 0) {
                    break;
                }
                j--;
            }
            temp = k;
            j = curr + 1;
            while (temp > 0) {
                if (j == 26) {
                    break;
                }
                currans = Math.max(currans, array[j] + 1);
                temp--;
                if (j == 25) {
                    break;
                }
                j++;
            }
            array[curr] = Math.max(currans, array[curr]);
            ans = Math.max(ans, array[curr]);
        }
        return ans;
    }
}
