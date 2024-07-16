class Solution {
    public String printString(String s, char ch, int count) {
       int cn = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == ch){
                cn++;
            } if(cn == count){
               return s.substring(i+1);
            }
        }
        return ""; 
    }
}
