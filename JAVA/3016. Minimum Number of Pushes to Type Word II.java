class Solution {
    public int minimumPushes(String word) {
        int[] mp = new int[26];
        for (char ch : word.toCharArray()) {
            mp[ch - 'a']++;
        }
        Integer[] mpInteger = Arrays.stream(mp).boxed().toArray(Integer[]::new);
        Arrays.sort(mpInteger, Comparator.reverseOrder());
        int ans = 0;
        int weight = 1;
        for (int i = 0; i < 26 && mpInteger[i] > 0; i++) {
            ans += mpInteger[i] * weight;
            if ((i + 1) % 8 == 0) {
                weight++;
            }
        }
        return ans;
    }
}
