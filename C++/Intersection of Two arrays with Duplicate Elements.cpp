class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        vector<int> result{};
        unordered_map<int,int> mp;        
        for(auto& i : a)
        {
            mp[i]++;
        }
        for(auto& i : b)
        {
            if( mp[i])
            {
                result.push_back(i);
                mp[i] = 0;
            }
        }
        return result;
    }
};
