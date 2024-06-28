class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int>m;
        for(int i=0; i<roads.size(); i++){
            int x=roads[i][0];
            int y=roads[i][1];
            m[x]++;
            m[y]++;
        }
        vector<long long>v;
        for(auto it:m)v.push_back(it.second);
        sort(v.begin(),v.end());        
        long long res=0;
        for(long long i=v.size()-1,j=n; i>=0; i--,j--)res+=(v[i]*j);        
        return res;
    }
};
