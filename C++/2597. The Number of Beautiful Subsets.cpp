class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int answer = 0;
        int n = (int) nums.size();
        std::vector<int> f;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] - nums[i] == k) {
                    f.push_back((1 << i) | (1 << j));
                }
            }
        }
        for (int mask = 1; mask < (1 << n); ++mask) {
            bool ok = true;
            for (int v : f) {
                if ((mask & v)== v) {
                    ok = false;
                    break;
                }
            }
            answer += ok;
        }
        return answer;
    }
};
