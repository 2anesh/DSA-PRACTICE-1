class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAnd = *max_element(nums.begin(), nums.end());
        int len = 0;
        int res = 1;
        int n = nums.size();
        int i = 0;
        while(i < n){
            len = 0;
            while(i < n && nums[i] == maxAnd){
                res = max(res, ++len);
                i++;
            }
            i++;
        }
        return res;
    }
};
