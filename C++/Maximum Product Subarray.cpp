class Solution {
  public:
    int maxProduct(vector<int> &arr) {
      int n=arr.size();
      int maxi=INT_MIN;
      for(int i=0;i<n;i++)
      {
          int ans=1;
          for(int j=i;j<n;j++)
          {             
             ans*=arr[j];
             maxi=max(maxi,ans);
          }
      }
      return maxi;
    }
};
