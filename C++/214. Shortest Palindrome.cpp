class Solution {
public:
    string shortestPalindrome(string s) {
        int l = s.size();
        int i = 0;
        for(int j = l-1;j>=0;j--)
        {
            if(s[i]==s[j])
            {
                i++;
            }
        }
        if(i==l)
        {
            return s;
        }
        else
        {
            string temp = s.substr(i,l);
            reverse(temp.begin(),temp.end());
            return temp + shortestPalindrome(s.substr(0,i))+s.substr(i);
        }
    }
};
