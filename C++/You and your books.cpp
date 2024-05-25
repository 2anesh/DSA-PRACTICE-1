class Solution {
  public:
    long long max_Books(int arr[], int n, int k) {
        long long maxi=0,sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                sum+=arr[i];
                maxi=max(maxi,sum);
            }
            else{
                sum=0;
            }
        }
        return maxi;
    }
};
