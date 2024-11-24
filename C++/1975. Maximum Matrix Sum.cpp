class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0; 
        int mult = 0, small = INT_MAX; 
        for (auto& row : matrix) {
            for (auto& x : row) {
                ans += abs(x); 
                small = min(small, abs(x)); 
                if (x < 0) mult ^= 1; 
            }
        }
        return ans - 2*mult*small; 
    }
};
