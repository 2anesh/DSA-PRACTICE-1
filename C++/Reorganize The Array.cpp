class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,-1);       
        for(auto i:arr)
        {
            if(i!=-1)
            {
                ans[i]=i;
            }
        }
        return ans;
    }
};
