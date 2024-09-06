class Solution {
  public:
    long long maxSubarraySum(vector<int> &arr) {
         long long ans=INT_MIN;
         long long sum=0;
         for(int i=0;i<arr.size();i++){
             sum +=arr[i];
             ans=max(ans,sum);
             if(sum<0)
             sum=0;
         }
         return ans;
    }
};
