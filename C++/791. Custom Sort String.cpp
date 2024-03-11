class Solution {
public:
    string customSortString(string order, string s) {
        int n = 200;
        unordered_map<char,int>m;
        for(int i=0; i<order.length(); i++){
            m[order[i]]=n--;
        }
        vector<pair<int,char>>x;
        for(int i=0; i<s.length(); i++){
            if(m[s[i]]<1){x.push_back({0, s[i]}); continue;}
            x.push_back({m[s[i]], s[i]});
        }
        sort(x.begin(), x.end());
        int p=0;
        for(int i=x.size()-1; i>=0; i--){
            s[p++] = x[i].second;
        }
        return s;
    }
};
