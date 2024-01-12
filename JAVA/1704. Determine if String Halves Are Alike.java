class Solution {
    public boolean halvesAreAlike(String s) {
        int c1 = 0;
        int c2 = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            String charStr = String.valueOf(ch);

            if (("a".equals(charStr) || 
                 "e".equals(charStr) || 
                 "i".equals(charStr) || 
                 "o".equals(charStr) || 
                 "u".equals(charStr) || 
                 "A".equals(charStr) || 
                 "E".equals(charStr) || 
                 "I".equals(charStr) || 
                 "O".equals(charStr) || 
                 "U".equals(charStr)) && (i < s.length() / 2)) {
                c1++;
            } else if ("a".equals(charStr) || 
                       "e".equals(charStr) || 
                       "i".equals(charStr) || 
                       "o".equals(charStr) || 
                       "u".equals(charStr) || 
                       "A".equals(charStr) || 
                       "E".equals(charStr) || 
                       "I".equals(charStr) || 
                       "O".equals(charStr) || 
                       "U".equals(charStr)) {
                c2++;
            }
        }

        return c1 == c2;
    }
}
