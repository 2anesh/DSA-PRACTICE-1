class Solution {
public:
int mod=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
       long long ans=0;
        vector<int>ls(n+1,0);
        for(auto it:requests)
        {
            int st=it[0];
            int end=it[1];
            ls[st] +=1;
            ls[end+1] -=1;
        }
        multimap<int,int>mp;
        int s=0;
        for(int i=0;i<n;i++)
        {
            s +=ls[i];
           mp.insert({s,i});
        }       
       int i=0;
        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {
            long long freq=it->first;
            int index=it->second;
           ans=(ans+(freq*nums[i])%mod)%mod;
           i++;
        }
  return ans;
    }
};
