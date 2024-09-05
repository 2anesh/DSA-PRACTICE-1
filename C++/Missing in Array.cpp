class Solution {
  public:
    int missingNumber(int n, vector<int>& arr) {
         long long cnt = n * (n+1)/2;
         long long s = accumulate(arr.begin(), arr.end(), 0LL);
         return cnt - s;
    }
};
