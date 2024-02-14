class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        std::vector<int> arr1, arr2;       
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        int j = 1;
        for(int i = 0; i < arr2.size(); i++) {
            arr1.insert(arr1.begin() + j, arr2[i]);
            j += 2;  
        }
        return arr1;
    }
};
