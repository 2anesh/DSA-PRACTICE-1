class Solution
{
    boolean kPangram(String str, int k) 
    {
        str=str.replace(" ","");
        int n=str.length();
        if(n<26) return false;
        int count[]=new int[26];
        for(int i=0;i<n;i++) count[str.charAt(i)-'a']++;
        int c=0;
        for(int i=0;i<26;i++)
        {
            if(count[i]==0) c++;
        }
        
        return c<=k;
    }
}
