class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
            if(i < j && s[i] != s[j]) return j-i+1;
            i++;
            while(s[i] == s[i-1]) i++;
            j--;
            while(i < j && s[j] == s[j+1]) j--;
        }
        if(j<i) return 0;
        return j-i+1;
    }
};
