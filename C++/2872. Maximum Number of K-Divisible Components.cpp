class Solution {
public:
    int count=0;
    vector<bool>vst;
    long long dfs(vector<vector<int>>&adj,vector<int>&val,int &k,int node)
    {
        vst[node]=true;
        long long sum = 0;
        for(int x:adj[node])
        {
            // long long t=-1;
            if(!vst[x])
            sum += dfs(adj,val,k,x);
        }
        sum += val[node];
        if(sum%k == 0)
        count++;
        
        return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& val, int k) {
        vst.resize(n,0);
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(adj,val,k,0);
        return count;
    }
};
