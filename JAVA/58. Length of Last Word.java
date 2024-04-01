class Solution {
    public int lengthOfLastWord(String s) {
        char[] ans = s.toCharArray();
        int count=0;
        boolean flag = false;
        for(int i=ans.length-1; i>=0; i--)
        {
            
            if(ans[i]!=' '){
                count++;
                flag=true;
            }
            else {
                if(flag==true)
                    break;
            }
        }
        return count;
    }
}
