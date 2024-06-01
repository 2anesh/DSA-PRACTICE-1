class Solution {
    public static String oddEven(String s) {
        int charArr[]=new int[27];
        for(int i =0;i<s.length();i++){
            char ch=s.charAt(i);
            charArr[ch-'a']++;
        }
        int x=0;
        int y=0;
        
        for (int i=0; i<27;i++){
            if(charArr[i]!=0 && charArr[i]%2==0 && (i+1)%2==0)x++;
            else if(charArr[i]%2!=0 && (i+1)%2!=0)y++;
    
        }
        int ans= x+y;
        return (ans&1)==1?"ODD":"EVEN";
        
    }
}
