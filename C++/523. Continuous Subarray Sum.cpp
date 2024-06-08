class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int psum=0;
        unordered_map<int,int>mp;
        int n=nums.size();        
        for(int i=0;i<n;i++)
        {
            psum+=nums[i];
            psum%=k;
            int s=i+1;
            if(s>1 && psum==0)
            return true;
            if(mp.find(psum)!=mp.end())
            {
                int j=mp[psum];
                if(i-j>1 )
                return true;
            }
            else
            mp[psum]=i;
        }
        return false;
    }
};
