class Solution
{
    int atoi(String s) {
        if(!isValid(s)) return -1;
        return Integer.parseInt(s);
    }
    private boolean isValid(String s){
        if(s.charAt(0) != 45 && s.charAt(0)<48 || s.charAt(0)>57) return false;
        for(int i=1; i<s.length(); i++){
            if(s.charAt(i)<48 || s.charAt(i)>57) return false;
        }
        return true;
    }
}
