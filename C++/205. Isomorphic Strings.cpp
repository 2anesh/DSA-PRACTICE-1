class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> charMap;
        unordered_set<int> set;
        for(int i = 0; i < n; i++) {
            if(charMap.count(s[i])) {
                if(charMap[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if(set.count(t[i])) {
                    return false;
                }
                charMap[s[i]] = t[i];
                set.insert(t[i]);
            }
        }
        return true;
    }
};
