struct Ans {
    int left;
    int right;
};
class Solution {
public:
    bool find(unordered_map<char, int> &map, char x) {
        return map.find(x) != map.end();
    }
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;
        for(char i: t) {
            t_map[i]++;
        }
        int left = 0;
        int right = 0;
        int cnt = 0;
        int globalMin = INT_MAX;
        struct Ans ans;
        ans.left = -1;
        ans.right = -1;        
        for(right = 0; right < n; right++) {
            s_map[s[right]]++;
            if(find(t_map, s[right]) and s_map[s[right]] == t_map[s[right]]) {
                cnt++;
            }
            while (cnt == t_map.size()) {
                int currSize = right - left + 1;
                if(currSize < globalMin) {
                    globalMin = currSize;
                    ans.left = left;
                    ans.right = right;
                }
                s_map[s[left]]--;
                if(find(t_map, s[left])) {
                    if(s_map[s[left]] < t_map[s[left]]) {
                        cnt--;
                    }
                }
                left++;
            }             
        }
        if(ans.left == -1 || ans.right == -1) {
            return "";
        }
        int subStrSize = ans.right - ans.left + 1;
        return s.substr(ans.left, subStrSize);
    }
};
