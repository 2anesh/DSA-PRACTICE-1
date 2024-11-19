class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int i = 0, j = 0;
        long long maxSum = 0, currentSum = 0;
        while (j < nums.size()) {
            if (j - i + 1 > k) {
                myMap[nums[i]]--;
                if(myMap[nums[i]] == 0)
                    myMap.erase(nums[i]);
                currentSum -= nums[i];
                i++;
            }
            myMap[nums[j]]++;
            currentSum += nums[j];
            if(myMap.size()==k)
                    maxSum = max(maxSum,currentSum);
            j++;
        }
        return maxSum;
    }
};
