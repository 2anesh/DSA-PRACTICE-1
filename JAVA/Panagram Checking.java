class Solution
{
    public static boolean checkPangram  (String s) {
        int[] arr = new int[26];
        
        for(int i=0;i<s.length();i++){
            char c = Character.toLowerCase(s.charAt(i));
            if((c - 'a') >= 0 && c - 'a' <= 26){
                arr[c -'a']++;
            }
        }
        for(int i=0;i<arr.length;i++){
            if(arr[i] == 0){
                return false;
            }
        }
        return true;
    }
}
