class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans; 
        for (auto x : nums) {
            x = abs(x); 
            if (nums[x-1] < 0) ans.push_back(x); 
            nums[x-1] *= -1; 
        }
        return ans; 
    }
};
