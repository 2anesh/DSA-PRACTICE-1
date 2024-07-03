class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)return 0;
        sort(nums.begin(),nums.end());
        int x=nums[n-4]-nums[0];
        int y=nums[n-1]-nums[3];
        int z=nums[n-3]-nums[1];
        int w=nums[n-2]-nums[2];
        return min({x,y,z,w});
    }
};
