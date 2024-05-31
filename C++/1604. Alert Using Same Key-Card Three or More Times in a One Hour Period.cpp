class Solution {
public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    vector<string> ans;
    unordered_map<string, vector<int>>table;    
    for(int i = 0; i != keyName.size(); i++)
      table[keyName[i]].push_back(((keyTime[i][0]-'0')*10 + (keyTime[i][1]-'0'))*60 + (keyTime[i][3]-'0')*10 + keyTime[i][4]-'0');   
    for(auto &[name, v]: table){
      sort(v.begin(), v.end());
      for(int i = 2; i < v.size(); i++)
        if(v[i] - v[i-2] <= 60){
          ans.push_back(name);
          break;
        }
    }    
    sort(ans.begin(), ans.end());  
    return ans;
  }
};
