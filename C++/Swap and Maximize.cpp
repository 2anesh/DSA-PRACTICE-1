class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> nums; 
        sort(arr.begin(), arr.end());
        int i=0; int j = n-1;
        while(i <= j){
            if(i == j){
                nums.push_back(arr[i]);
            }else{
                nums.push_back(arr[i]);
                nums.push_back(arr[j]);
            }
            i++;
            j--;
        }
        long long sum = 0;
        for(int i=0 ;i<n-1; i++){
            sum += abs(nums[i] - nums[i+1]);
        }
        sum += abs(nums[n-1] - nums[0]);
        return sum;
        
    }
};
