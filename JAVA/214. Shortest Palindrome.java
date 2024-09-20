class Solution {
    public String shortestPalindrome(String s) {
        if(s == null || s.length() <= 1) {
            return s;
        }
        String rev_s = new StringBuilder(s).reverse().toString();
        int n = s.length();
        int i = 0;
        while(i < n) {
            if(s.substring(0, n - i).equals(rev_s.substring(i))) {
                break;
            }
            i++;
        }
        return rev_s.substring(0, i) + s;
    }
}
