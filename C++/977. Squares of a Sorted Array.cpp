class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                idx = i;
            } 
            nums[i] = nums[i]*nums[i];
        }
        if(idx == -1){
            return nums;
        }
        vector<int> updated_array; int j = idx+1;
        while(idx >= 0 and j<nums.size()){
            if(nums[idx] < nums[j]){
                updated_array.push_back(nums[idx]);
                idx--;
            }
            else{
                updated_array.push_back(nums[j]);
                j++;
            }
        }
        
        while(idx >= 0){
            updated_array.push_back(nums[idx]);
            idx--;
        }
        
        while(j < nums.size()){
            updated_array.push_back(nums[j]);
            j++;
        }
        
        return updated_array;
    }
};
