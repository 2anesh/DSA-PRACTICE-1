class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> prefixSumFreq;
        int prefixSum = 0;
        int count = 0;        
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            if (prefixSum == goal) {
                count++;
            }
            if (prefixSumFreq.count(prefixSum - goal)) {
                count += prefixSumFreq[prefixSum - goal];
            }
            prefixSumFreq[prefixSum]++;
        }        
        return count;
    }
};
