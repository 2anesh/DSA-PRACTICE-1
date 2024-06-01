class Solution {
public:
    int scoreOfString(string s) {
        string v = s;
        int score = 0;
        for(int i=0; i<v.length()-1; i++)
        {
            score += int(abs(s[i]-s[i+1]));
        }
        return score;
    }
};
