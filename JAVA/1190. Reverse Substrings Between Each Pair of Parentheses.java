class Solution {
     public static void main(String[] args) {
        String s = "(ed(et(oc))el)";
        Solution bp = new Solution();
        bp.reverseParentheses(s);
    }
    public String reverseParentheses(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                count++;
            }
        }
        for (int j=0;j<count;j++) {
            int RP = s.indexOf(')');
            int LP = s.lastIndexOf('(', RP);
            String innenString = s.substring(LP + 1, RP);
            String reversedSubstring = new StringBuilder(innenString).reverse().toString();
            String resultString = s.substring(0, LP) + reversedSubstring + s.substring(RP + 1);
            s = resultString;
        }
        return s;
    }
}
