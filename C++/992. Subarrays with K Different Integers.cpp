class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countK(nums, k) - countK(nums, k - 1);
    }    
private:
    int countK(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int left = 0;
        int distinct_count = 0;
        int result = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (counter[nums[right]] == 0) {
                distinct_count++;
            }
            counter[nums[right]]++;
            while (distinct_count > k) {
                counter[nums[left]]--;
                if (counter[nums[left]] == 0) {
                    distinct_count--;
                }
                left++;
            }
            result += right - left + 1;
        }
        return result;
    }
};
