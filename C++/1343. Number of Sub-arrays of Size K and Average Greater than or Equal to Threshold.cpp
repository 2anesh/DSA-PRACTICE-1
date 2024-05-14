class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        if(k == 0 || nums.size() <= 0)
            return 0;
        double sum = 0.0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            if(i + 1 >= k)
            {
                double avg = sum/(k);
                if(avg >= threshold)
                    count++;
                sum -=nums[i-k+1];
            }
        }
        return count;
    }
};
