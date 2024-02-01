class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;        
        int n = nums.size();
        int idx = 0;
        while (idx < n) {
            if (idx + 2 < n && nums[idx + 2] - nums[idx] <= k) {
                res.push_back({nums[idx], nums[idx + 1], nums[idx + 2]});
                idx += 3; 
            } else {
                return {};
            }
        }

        return res; 
    }
};
