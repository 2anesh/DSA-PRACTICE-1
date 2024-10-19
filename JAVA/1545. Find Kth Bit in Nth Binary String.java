class Solution {      
    public String reverse(String s) {
        int n = s.length();
        StringBuilder sb = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {   
            sb.append((char)((int)s.charAt(i) ^ 1));  
        }
        return sb.toString();
    }
    public char findKthBit(int n, int k) {
        String s = "0";  
        for (int i = 1; i < n; i++) {
            s = s + "1" + reverse(s);  
        }
        System.out.println(s); 
        return s.charAt(k - 1);  
    }
}
