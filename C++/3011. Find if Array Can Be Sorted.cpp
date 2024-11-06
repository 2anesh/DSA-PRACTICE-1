class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while(n) {
            count += (n & 1);  
            n >>= 1;          
        }
        return count;
    }
    
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> setBits(n);
        for(int i = 0; i < n; i++) {
            setBits[i] = countSetBits(nums[i]);
        }
        bool swapped;
        do {
            swapped = false;
            for(int i = 0; i < n-1; i++) {
                if(setBits[i] == setBits[i+1] && nums[i] > nums[i+1]) {
                    swap(nums[i], nums[i+1]);
                    swapped = true;
                }
            }
        } while(swapped);
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) return false;
        }
        
        return true;
    }
};
