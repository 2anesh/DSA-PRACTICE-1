class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());         
        auto fn = [&](int x) {
            int ans = 0; 
            for (int i = 0, ii = 0; i < nums.size(); ++i) {
                for (; ii < i && nums[i] - nums[ii] > x; ++ii); 
                ans += i - ii; 
            }
            return ans; 
        };         
        int lo = 0, hi = nums.back() - nums.front(); 
        while (lo < hi) {
            int mid = lo + (hi - lo)/2, y = fn(mid); 
            if (y < k) lo = mid + 1; 
            else hi = mid; 
        }
        return lo; 
    }
};
