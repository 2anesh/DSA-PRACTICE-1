class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int res = 0;
        if(k == 0){
            return res;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            long long temp = 1;
            for(int j = i ; j < nums.size() ; j++){
                temp = nums[j]*temp;
                if(temp<k){
                    res++;
                }else{
                    break;
                }
            }
        }
        return res;
    }
};
