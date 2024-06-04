class Solution {
    public int longestPalindrome(String s) {
        int length = 0;
        Set<Character> set = new HashSet<>();
        for(char c : s.toCharArray()){
            if(!set.add(c)){
                set.remove(c);
                length+= 2;
            }
        }       
        if(!set.isEmpty()){
            length += 1;
        } 
        return length;
    }
} 
