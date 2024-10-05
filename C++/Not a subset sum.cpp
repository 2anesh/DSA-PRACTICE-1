class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        long long ans = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > ans )return ans;
            else {
                ans = ans+arr[i];
            }
        }
        return ans;
    }
};
