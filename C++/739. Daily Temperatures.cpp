class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(); 
        vector<int> res(n); 
        stack<int> stk; 
        for (int i = 0; i < n; ++i) {
            while (stk.size() && temperatures[stk.top()] < temperatures[i]) {
                int ii = stk.top(); stk.pop(); 
                res[ii] = i - ii; 
            }
            stk.push(i); 
        }
        return res; 
    }
};
