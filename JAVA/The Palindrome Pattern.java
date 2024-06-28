class Solution {
     public static boolean isPalindrome(String data){
        String rev="";
        for(int i=0;i<data.length();i++){
            rev=data.charAt(i)+rev;
        }
        if(rev.equals(data))
            return true;
        return false;
    }
    public String pattern(int[][] arr) {
        String element="";
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr.length;j++){
                element+=Integer.toString(arr[i][j]);
            }
            if(isPalindrome(element))
                return Integer.toString(i)+" R";
            element="";
        }
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr.length;j++){
                element+=Integer.toString(arr[j][i]);
            }
            if(isPalindrome(element))
                return Integer.toString(i)+" C";
            element="";
        }
        return "-1";
    }
}
