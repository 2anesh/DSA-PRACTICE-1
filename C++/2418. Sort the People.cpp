class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       map<int,string, greater<int>>mp;  // map to store in decending order   
    int n = names.size();
        for(int i=0; i<n; i++){
            mp[heights[i]] = names[i];
        }      
      vector<string>res;
        for(auto &p:mp){
            res.push_back(p.second);
        }
        return res;
    }
};
