class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> bits(31, 0);
        for(auto num : nums){
            for(int i = 30; i>=0; i--){
                int bit = (1<<i);
                if(bit & num){
                    bits[i]++;
                }
            }
        }
        int ans = 0;
        for(int i = 30; i>=0; i--){
            if(bits[i] > 0){
                ans += (1<<i);
            }
        }
        return ans;
    }
};
