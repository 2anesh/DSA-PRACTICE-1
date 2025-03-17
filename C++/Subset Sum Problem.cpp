class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<bool>prev(sum+1, 0);
        prev[0]=1;
        for(int i=1; i<=n; i++){
            vector<bool>curr(sum+1, 0);
            curr[0]=1;
            for(int t=0; t<=sum; t++){
                bool take=0;
                if(t>=arr[i-1]) take=prev[t-arr[i-1]];
                curr[t]=take|prev[t];
            }
            prev=curr;
        }
        return prev[sum];
    }
};
