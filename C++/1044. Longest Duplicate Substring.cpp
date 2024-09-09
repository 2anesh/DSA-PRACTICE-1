class Solution {
public:
    string longestDupSubstring(string S) {
        int start = 0;
        int end = S.size()-1;
        string_view ans;
        unordered_set<string_view> seen;
        while (start <= end){
            int len = start + ((end-start)>>1);
            bool found = false;
            for (int i = 0; i < S.size()+1-len; i++){             
                string_view str = string_view(S).substr(i, len);   
                if (seen.count(str)){                              
                    ans = str;
                    found = true;
                    break;
                } else
                    seen.emplace(str);
            }
            if (found)
                start = len+1;
            else
                end = len-1;       
            seen.clear();           
        }
        return {ans.begin(),ans.end()};    
    }
};
