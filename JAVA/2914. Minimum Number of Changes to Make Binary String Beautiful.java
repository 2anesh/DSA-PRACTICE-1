class Solution {
    public int minChanges(String s) {
        char[] arr = s.toCharArray();
        int cnt = 0;
        for (int i = 0; i < arr.length - 1; i += 2) {
            if (arr[i] != arr[i + 1]) {
                cnt++;
            }
        }        
        return cnt;
    }
}
