class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk; 
        for (auto& x : nums) {
            while (stk.size() && gcd(stk.back(), x) > 1) {
                x = lcm(x, stk.back()); 
                stk.pop_back(); 
            }
            stk.push_back(x); 
        }
        return stk; 
    }
};
