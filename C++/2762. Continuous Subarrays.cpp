class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result=0;
        int left=0;
        deque<int>maxdq;
        deque<int>mindq;

        for(int i=0;i<nums.size();i++){
            while(!maxdq.empty() && nums[maxdq.back()]<=nums[i]){
                maxdq.pop_back();
            }
            maxdq.push_back(i);

             while(!mindq.empty() && nums[mindq.back()]>=nums[i]){
                mindq.pop_back();
            }
            mindq.push_back(i);

            while(nums[maxdq.front()]-nums[mindq.front()]>2){
                if(maxdq.front()==left){
                    maxdq.pop_front();
                }
                 if(mindq.front()==left){
                    mindq.pop_front();
                }
                left++;
            }

            result+=(i-left+1);

        }

        return result;
    }
};
