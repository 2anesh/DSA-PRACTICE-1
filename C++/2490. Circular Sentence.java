class Solution {
public:
    bool isCircularSentence(string s) {
        char last = s[0]; 
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == ' ') { 
                if(last != s[i + 1]) return false;
            } else {
                last = s[i];
            }
        }
        return last == s[0];
    }
};
