class Solution {
public:
    int minimumDeletions(vector<int>& nums) {        
        int big = INT_MIN;
        int b;                 
        int small = INT_MAX;
        int s;                 
        int n = nums.size();        
        for(int i=0; i<n; i++){
            if(nums[i] > big){
                big = nums[i];
                b = i+1;
            }
            if(nums[i] < small){
                small = nums[i];
                s = i+1;
            }
        }        
        int x = min(max(b,s), max(n-b+1, n-s+1));
        int y = min(b+n-s+1, s+n-b+1);        
        return min(x, y);       
    }
};
