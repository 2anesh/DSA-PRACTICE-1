class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
         
         while(r--)
         {
             string temp = "";
             for(int i=0;i<s.length();i++)
             {
                 if(s[i]=='1') temp+="10";
                 else temp+="01";
                 
                 if(temp.length()*pow(2,r)>=n+1) break;
             }
             s = temp ; 
         }
         return s[n];
    }
};
