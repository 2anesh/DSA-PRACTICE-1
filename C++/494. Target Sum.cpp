class Solution {
public:
    int find(vector<int>& nums, int i, int sum,
            vector<vector<int>>& dp, int offset){
        if(i == 0){
            if(sum+nums[i] == 0 || sum-nums[i] == 0) 
            if(nums[i] == 0) return 2;
            else return 1;
            else return 0;
        }
        if(sum+offset < 0 || sum+offset >= dp[0].size()) return 0;
        if(dp[i][sum+offset] != -1) return dp[i][sum+offset];
        int add = find(nums, i-1, sum+nums[i], dp, offset);
        int sub = find(nums, i-1, sum-nums[i], dp, offset);
        return dp[i][sum+offset] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = 0;
        for(int i=0; i<n; i++) offset += nums[i];
        vector<vector<int>> dp(n, vector<int>(offset*2+1, -1));
        return find(nums, n-1, target, dp, offset);
    }
};
