class Solution {
  public:
    string reverseWords(string str) 
    {
        stack<string>s;
        string newstr="";
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            string word="";
            
            while(i<n && str[i]!='.')
            {
                word+=str[i];
                i++;
            }
            s.push(word);
        }
         while(!s.empty()) 
        {
            newstr += s.top();
            s.pop();
            if (!s.empty()) 
            {
                newstr += ".";
            }
        }
        return newstr;
    }
};
