class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        unordered_map<int, int> freq; 
        for (auto& x : stones) freq[x % 3]++; 
        if (freq[0] & 1) return abs(freq[1] - freq[2]) >= 3; 
        return freq[1] && freq[2]; 
    }
};
