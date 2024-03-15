class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int product = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            product = product * nums[i];
            output.push_back(product);
        }
        product = 1;
        for(int j = nums.size()-1; j > 0 ; j--)
        {
            output[j] = product * output[j-1];
            product *= nums[j];
        }
        output[0] = product;
        return output;
    }
};
