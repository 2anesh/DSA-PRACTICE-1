class Solution {
public:
    string makeFancyString(string s) {
        int ii = 1; 
        for (int i = 2; i < s.size(); ++i) {
            if (s[ii-1] == s[ii] && s[ii] == s[i]) continue; 
            s[++ii] = s[i]; 
        }
        return s.substr(0, ++ii); 
    }
};
