class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        while(i < j){
            if(nums[i] * nums[j] > 0) break;
            if(nums[i] * -1 == nums[j]) return nums[j];
            if(nums[i] * -1 < nums[j]) j--;
            else i++;

        }
        return -1;
    }
};
