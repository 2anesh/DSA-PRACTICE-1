class Solution {
    public boolean checkValidString(String s) {
        int bal=0;
        for(char c:s.toCharArray()) {
            if(c=='('||c=='*') {
                bal++;
            } else {
                bal--;
            }
            if(bal<0) {
                return false;
            }
        }
        bal=0;
        for(int i=s.length()-1;i>=0;i--) {
            char c=s.charAt(i);
            if(c==')'||c=='*') {
                bal++;
            } else {
                bal--;
            }
            if(bal<0) {
                return false;
            }
        }
        return true;
    }
}
