class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mp;
        for(int i=0;i<arr.size();i++){
            string str=arr[i];
            vector<int>freq(26,0);
            for(auto x:str)
            freq[x-'a']++;
            
            if(mp.find(freq)!=mp.end()){
                mp[freq].push_back(str);
            }
            else
            mp[freq]={str};
            
        }
        for(auto x:mp)
        ans.push_back(x.second);
        return ans;
    }
};

