class Solution {
  public:
    int mod = 1e9+7;
    vector<int> Series(int n) 
    {
        vector<int> ans(n+1,0);
        ans[1]=1;
        for(int i=2;i<=n;i++)
        {
            ans[i] = (ans[i-1]+ans[i-2])%mod;
        }
        return ans;
    }
};
