class Solution {
public:
    int getNumberOfOpToBagSize(vector<int>& nums, int maxBagSize) {
        int totalOperations = 0;
        for(int num : nums) {
            int curOperations = (num + maxBagSize - 1) / maxBagSize;
            totalOperations += curOperations-1;
        }

        return totalOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int minPenalty = 1;
        int maxPenalty = *max_element(nums.begin(), nums.end());

        int ans = maxPenalty;
        
        while(minPenalty <= maxPenalty) {
            int curPenalty = minPenalty + (maxPenalty - minPenalty) / 2;
            int curOperations = getNumberOfOpToBagSize(nums,curPenalty);
            bool isPossible = curOperations <= maxOperations;

            if(isPossible) {
                ans = curPenalty;
                maxPenalty = curPenalty - 1;
            } else {
                minPenalty = curPenalty + 1;
            }
        }

        return ans;
    }
};
