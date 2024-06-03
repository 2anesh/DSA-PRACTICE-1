class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        while(i<t.size() && j<s.size())
        {
            if(s[j]==t[i])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return t.size()-i;        
    }
};
