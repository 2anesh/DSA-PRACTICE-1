class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<int> dq; 
        int ans = 0, flip = 0;         
        for (int i = 0; i < size(nums); ++i) {
            if (size(dq) && dq.front() == i) {
                dq.pop_front(); 
                flip ^= 1; 
            }
            if (nums[i] == flip) {
                if (size(nums)-i < k) return -1; 
                ++ans; 
                flip ^= 1; 
                dq.push_back(i+k); 
            }
        }
        return ans; 
    }
};
