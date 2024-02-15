class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long int sum = 0 ;
        for(int i=0;i<n-1;i++){
            sum += nums[i];
        }
        int i = n-2 , j = n-1;
        while((j+1) >= 3){
            if(sum > nums[j]){
                return sum+nums[j];
            }
            else{
                sum -= nums[i];
                i--;
                j--;
            }
        }
        return -1;
    }
};
