class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int adjustedMin = nums[0] - k;
        int adjustedMax = nums[n - 1] + k;

        int maxBeauty = 0; 
        for (int targetValue = adjustedMin; targetValue <= adjustedMax; targetValue++) {
            int lowerBoundCnt = lower_bound(nums.begin(), nums.end(), targetValue - k) - nums.begin();
            int upperBoundCnt = lower_bound(nums.begin(), nums.end(), targetValue + k + 1) - nums.begin();
            int currentBeauty = upperBoundCnt - lowerBoundCnt;
            maxBeauty = max(maxBeauty, currentBeauty);
        }
        return maxBeauty;
    }
};
