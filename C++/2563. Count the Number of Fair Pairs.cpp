class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
           int l=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
          int r=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
          ans+=r-l;
        }
        return ans;
    }
};
