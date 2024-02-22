class Solution
{
int  subsequenceCount(String s, String t)
    {
        int[]prev = new int[t.length()+1];
        prev[0] = 1;
        for(int i = 1; i<=s.length();i++){
            int[]curr = new int[t.length()+1];
            curr[0] = 1;
            for(int j = 1; j<=t.length();j++){
                 int notPick = prev[j]%1000000007;
                 int pick = 0;
                 if(s.charAt(i-1) == t.charAt(j-1)){
                    pick = prev[j-1]%1000000007;
                 }
                 curr[j] = (notPick + pick)%1000000007;
            }
            prev = curr;
        }
        return prev[t.length()];
    }
}
