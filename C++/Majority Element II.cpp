class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        map<int,int> mp;
        vector<int> res;
        for(int i=0;i<arr.size();i++)
        {
            
        mp[arr[i]]++;
              
        }
        for(auto x:mp)
        {
            if(x.second>arr.size()/3)
            {
                res.push_back(x.first);
            }
        }
        return res;
    }
};
