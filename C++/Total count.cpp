class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int a=arr[i];
            int c=a/k;
            int b=a%k;
            if(b>0)
            ans+=1+c;
            else ans+=c;
        }
        return ans;
    }
};
