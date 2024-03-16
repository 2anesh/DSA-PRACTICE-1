class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0, sum = 0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0; i<nums.size(); i++)
        {
            sum += (nums[i]==1)?1:-1; 
            
            if(mp.find(sum) != mp.end()) 
                max_len = max(max_len, i-mp[sum]);
            else
                mp[sum]=i;
        }
        return max_len;
    }
};
