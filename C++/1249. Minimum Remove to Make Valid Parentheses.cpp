class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int close = 0, diff = 0; 
        for (auto& ch : s) 
            if (ch == ')') ++close;        
        string ans; 
        for (auto& ch : s) {
            if (ch == '(') {
                if (diff < close) ++diff; 
                else continue; 
            } else if (ch == ')') {
                --close; 
                if (diff > 0) --diff; 
                else continue; 
            }
            ans.push_back(ch); 
        }
        return ans; 
    }
};
