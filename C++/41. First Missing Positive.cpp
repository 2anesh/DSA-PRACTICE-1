class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto& i:nums)
        {
            if(i>0)
            seen.insert(i);
        }
    int i=1;
    int n= nums.size();
    while(i<=n)
    {
        if(seen.count(i)==0)return i;
        i++;
    }
    return i;
    }
};
