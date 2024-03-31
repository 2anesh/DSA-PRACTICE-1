class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lmin  = -1;
        int lmax = -1;
        long long count = 0;
        int st = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>=minK and nums[i]<=maxK){
                if(minK==nums[i])lmin = i;
                if(maxK==nums[i])lmax = i;
                if(lmin!=-1 and lmax!=-1){
                    count = count + min(lmin,lmax)- st;
                }
            }
            else {
                st = i;
                lmin = lmax = -1;
            }
        }
        return count;
    }
};
