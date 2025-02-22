class Solution {
  public:
    int maxLength(string& s) {
        int maxlen = 0; // annswer
        vector<int>dp(s.size() , 0); 
        stack<int>open;
        for(size_t i = 0 ; i < s.size() ; i++) {
            if(s[i] == '(') {
                open.push(i); // push (i) stack
            } else {
                if(!open.empty()) {
                    dp[i] += 1; 
                    dp[open.top()] += 1;
                    open.pop(); // pop from stack 
                }
            }
        }
        for(int j = 1 ; j < dp.size() ; j++) {
            if(dp[j] == 0) continue; // if no balanced string starts at (j)
            dp[j] += dp[j - 1]; // prefix sum
            maxlen = std :: max(maxlen , dp[j]); // get max length of subsequent balanced string
        }
        return maxlen;
    }
};
