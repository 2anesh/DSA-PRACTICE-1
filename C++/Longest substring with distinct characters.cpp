class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();
        int i = 0, ans = 0;
        vector<int> freq(26, 0);
    
        for (int j = 0; j < n; j++) {
            int idx = s[j] - 'a'; 
            freq[idx]++;
    
            while (freq[idx] > 1) {
                freq[s[i] - 'a']--; 
                i++;
            }
    
            ans = max(ans, j - i + 1);
        }
    
        return ans;
    }
};
