class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        set <int> mp;
        for(auto& e: arr) mp.insert(e);
        vector <int> ans;
        for(auto& e: arr){
            if(mp.find(e) != mp.end()){
                ans.push_back(e);
                mp.erase(e);
            }
        }
        return ans;
    }
};
