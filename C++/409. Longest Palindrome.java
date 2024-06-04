class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (char x : s) {
            map[x]++;
        }

        int res = 0;
        bool oddFreq = false;
        for (auto x : map) {
            int freq = x.second;
            if (freq % 2 == 0) {
                res += freq;
            } else {
                res += freq - 1;
                oddFreq = true;
            }
        }
        if (oddFreq)
            return res + 1;
        return res;
    }
};
