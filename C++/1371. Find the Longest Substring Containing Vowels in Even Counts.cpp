class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        unordered_map<char, int> b_m {
            {'a', 1},
            {'e', 2},
            {'i', 4},
            {'o', 8},
            {'u', 16}
        }; 
        m[0] = -1;
        int mask = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            mask = mask ^ b_m[c];
            if(m.find(mask) != m.end()){
                res = max(res, i - m[mask]);
            }else{
                m[mask] = i;
            }
        }
        return res;
    }
};
