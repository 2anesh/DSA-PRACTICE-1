class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> freq (nums.size(), 0); 
        for (auto& x : nums) 
            ++freq[x-1];         
        vector<int> res(2, 0); 
        for (int i = 0; i < nums.size(); ++i) {
            if (freq[i] == 2) res[0] = i+1; 
            if (freq[i] == 0) res[1] = i+1; 
        }
        return res; 
    }
};
