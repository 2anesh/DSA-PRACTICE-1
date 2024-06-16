class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long patchs = 0, i = 0, reachedNum = 0;
        while(reachedNum < n){
            if(i < nums.size() && nums[i] <= reachedNum + 1){
                reachedNum += nums[i];
                i++;
            }
            else{
                reachedNum += (reachedNum + 1);
                patchs++;
            }
        }
        return int(patchs);
    }
};
