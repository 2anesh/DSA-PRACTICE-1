class Solution {
    bool findAns(int mid, map<char, vector<int>>& mp) {
        for (auto& x : mp) { 
            vector<int>& indices = x.second; 
            int sz = indices.size();
            int count = 0; 
            for (int i = 0; i < sz; ++i) {
                if (i + (mid - 1) < sz && indices[i + mid - 1] == indices[i] + mid - 1) {
                    ++count;
                }
                if (count >= 3)
                    return true;
            }
        }
        return false; 
    }
public:
    int maximumLength(string s) {
        map<char, vector<int>> mp;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            mp[s[i]].push_back(i);
        }
        
        int low = 1, high = n; 
        int ans = -1; 
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            
            if (findAns(mid, mp)) { 
                ans = mid;       
                low = mid + 1;  
            } else {
                high = mid - 1;  
            }
        }        
        return ans;
    }
};
