class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long count = 0;
        long long sum = 0;
        long long score = 0;
     
        for(int i = 0,j = 0; j < n;j++){
            sum+=nums[j];
            score=(sum*(j-i+1));
            
            while(score >= k ){
                sum-=nums[i];
                i++;
                score = sum*(j-i+1);
                
            }
            if(score < k){
                 count+=(j-i+1);   // there are (j-i+1) subarrays between index j and i
            }
        }
        return count;
    }
};
