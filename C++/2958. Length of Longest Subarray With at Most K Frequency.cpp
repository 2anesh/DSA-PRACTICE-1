class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> m;
        int last = 0;
        int answer = 0;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (++m[nums[i]] <= k) {
                answer = max({answer, i - last + 1});
            } else {
                while (last < i) {
                    --m[nums[last]];
                    if (m[nums[i]] == k && nums[i] == nums[last]) {
                        ++last;
                        break;
                    }
                    ++last;
                }
            }
            ++i;
        }
        return answer;
    }
};
