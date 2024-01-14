class Solution {
    public boolean closeStrings(String word1, String word) {
        int arr[]=new int[26];
        for(int i=0;i<word1.length();i++)
        {
           ++ arr[word1.charAt(i)-'a'];
        }         
         if(word1.length()!=word.length())
         return false;
       int ar[]=new int[26];
        for(int i=0;i<word.length();i++)
        {
           ++ ar[word.charAt(i)-'a'];
        }  
        for(int i=0;i<26;i++)
        if(arr[i]!=ar[i])
        {
         if(arr[i]==0 ||  ar[i]==0)
         return false;
        }
        Arrays.sort(arr);
        Arrays.sort(ar);
        for(int i=0;i<26;i++)
        if(arr[i]!=ar[i])
        {
         return false;
        }
        return true;
    }
}
