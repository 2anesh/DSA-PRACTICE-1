class Solution {
    static int swapNibbles(int n) {
        String s=Integer.toBinaryString(n);
        String curr="",ans="";
        for(int i=s.length()-1;i>=0;i--){
            curr=s.charAt(i)+curr;
            if(curr.length()==4){
                ans+=curr;
                curr="";
            }
        }
        if(curr.length()!=0){
            while(curr.length()!=4) curr='0'+curr;
            ans+=curr;
        }
        while(ans.length()<8) ans+='0';
        return Integer.parseInt(ans,2);
    }
}
