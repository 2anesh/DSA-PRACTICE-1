class Solution {
    public:
    vector<int> findOrder(int n, int m, vector<vector<int>> a) {
        vector<int> in(n, 0), topo, emptyArray;
        vector<int> adj[n];
        for(auto x: a) {
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++) {
            for(auto x: adj[i]) in[x]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(in[i]==0) q.push(i);
        while(q.size()) {
            int u=q.front(); q.pop();
            topo.push_back(u);
            for(auto x: adj[u]) {
                in[x]--;
                if(in[x]==0) q.push(x);
            }
        }
        return topo.size()==n?topo:emptyArray;
    }
};
