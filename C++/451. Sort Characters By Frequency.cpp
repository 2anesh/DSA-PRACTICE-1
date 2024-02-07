class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>v;
        map<char,int>m;
        for(int i=0; i<s.size(); i++)m[s[i]]++;
        for(auto it:m)v.push_back({-1*it.second,it.first});
        sort(v.begin(),v.end());
        string res;
        for(auto it:v){
            for(int i=1; i<=abs(it.first); i++){
                res+=it.second;
            }
        }        
        return res;
    }
};
