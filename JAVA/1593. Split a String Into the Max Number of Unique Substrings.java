class Solution {
    public int maxUniqueSplit(String s) {
     HashSet<String> st = new HashSet<>();
     int[] maxCount = new int[1];
     solve(s,0,0,st,maxCount);
     return maxCount[0];
    }
    private void solve(String s,int i,int currCount,HashSet<String> st,int[] maxCount)
    {
         if(currCount + (s.length() - i) <= maxCount[0]) return;
        if(i==s.length())
        {
            maxCount[0] = Math.max(maxCount[0],currCount);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            String sub = s.substring(i,j+1);
            if(!st.contains(sub))
            {
               st.add(sub);
               solve(s,j+1,currCount+1,st,maxCount);
               st.remove(sub);
            }
        }
    }
}
