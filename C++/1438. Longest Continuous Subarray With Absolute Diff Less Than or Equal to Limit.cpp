class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        deque<int> minDeque;
        deque<int> maxDeque;
        while (right < nums.size()) {
            while (!minDeque.empty() && nums[right] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);
            if (maxDeque.front() - minDeque.front() <= limit) {
                maxLength = max(maxLength, right - left + 1);
                ++right;
            } else {
                if (nums[left] == minDeque.front()) {
                    minDeque.pop_front();
                }
                if (nums[left] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                ++left;
                ++right;
            }
        }
        return maxLength;
    }
};
