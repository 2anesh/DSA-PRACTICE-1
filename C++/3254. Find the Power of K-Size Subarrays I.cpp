class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1)
            return nums;
        vector<int> ans;
        int n = nums.size();
        int i = 1, consecutiveSize = 1;
        while (i < n) {
            if (nums[i] - 1 == nums[i - 1]) {
                consecutiveSize += 1;
            } else {
                consecutiveSize = 1;
            }
            if (i >= k - 1) {
                ans.push_back(consecutiveSize >= k ? nums[i] : -1);
            }
            i += 1;
        }
        return ans;
    }
};
