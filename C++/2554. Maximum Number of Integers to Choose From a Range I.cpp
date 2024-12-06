class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> set(banned.begin(), banned.end());
        
        int count = 0;
        for (int i = 1; i <= n && maxSum >= i; i++) {
            if (set.find(i) == set.end()) {
                count++;
                maxSum -= i;
            }
        }
        return count;
    }
};
