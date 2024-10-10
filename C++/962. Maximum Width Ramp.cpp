class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty() || nums[i] < nums[s.top()]) {
                s.push(i);
            }
        }        
        int ans = 0;
        for (int j = n - 1; j >= 0; j--) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                ans = max(ans, j - s.top());
                s.pop();
            }
        }
        return ans;
    }
};
