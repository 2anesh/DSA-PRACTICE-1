class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0, x = 0;
        for (int i = 0; i < nums.size(); i++)
            x = x ^ nums[i];
        while (x > 0 || k > 0) {
            int a = x & 1, b = k & 1;
            if (a != b) count++; 
            x = x >> 1;
            k = k >> 1;
        }
        return count;
    }
};
