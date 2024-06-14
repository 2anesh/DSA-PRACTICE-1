class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minCount =0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] <= nums[i-1])
            {
                int increment = nums[i-1]+1 - nums[i];
                minCount += increment;
                nums[i] = nums[i-1]+1;
            }
        }
        return minCount;
    }
};
