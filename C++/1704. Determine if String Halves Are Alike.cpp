class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int c1=0,c2=0;
        int j=s.length()/2;
        vector<int>v,a;
        for(int i=0;i<s.length()/2;i++)
        {
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
             c1++;
        }
         for(int i=j;i<s.length();i++)
        {
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
             c2++;
        }
        if(c1==c2)
        return true;
        else
        return false;
            
    }
};
