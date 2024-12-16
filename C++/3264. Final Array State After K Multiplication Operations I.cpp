class Solution {
public:
    std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            auto minIt = std::min_element(nums.begin(), nums.end());
            *minIt *= multiplier;
        }
        return nums;
    }
};
