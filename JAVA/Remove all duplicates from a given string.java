class Solution {
    String removeDuplicates(String str) {

      int small[]=new int[26];
      int big[]=new int[26];
      String out="";
      
      for(int i=0;i<str.length();i++)
      {
          char ch=str.charAt(i);
          if(ch>=65 && ch<=90)
          big[ch-'A']++;
          else
          small[ch-'a']++;
      }
      
      for(int i=0;i<str.length();i++)
      {
          char ch=str.charAt(i);
          if(ch>=65 && ch<=90){
          if(big[ch-'A']>0)
          out+=ch;
          
          big[ch-'A']=0;
          }
          else{
           if(small[ch-'a']>0)
          out+=ch;
          
          small[ch-'a']=0;
          }
      }
      
      return out;

    }
}
