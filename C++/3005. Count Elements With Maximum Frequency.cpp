class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int max_freq = INT_MIN ;
        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
            max_freq = std::max(max_freq, freq[nums[i]]);
        }
        int ans = 0;
        for(auto val: freq){
            if(val == max_freq){
                ans += val;
            }
        }
    return ans;
 
    }
};
