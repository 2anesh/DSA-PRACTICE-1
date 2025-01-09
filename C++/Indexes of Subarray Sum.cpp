class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
     int start = 0, currentSum = 0;
    for (int end = 0; end < arr.size(); ++end) {
        currentSum += arr[end];
        while (currentSum > target && start <= end) {
            currentSum -= arr[start];
            start++;
        }
        if (currentSum == target) {
            return {start + 1, end + 1};
        }
    }
    return {-1};
  }
};
