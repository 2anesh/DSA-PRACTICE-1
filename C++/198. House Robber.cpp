class Solution {
public:
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0;
        for (auto& x : nums) {
            int f2 = max(f0+x, f1); 
            f0 = f1; 
            f1 = f2;
        }
        return f1; 
    }
};
