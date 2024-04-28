class Solution {
public:
    vector<int> dist, childs, SOD;
    pair<int, int> dfs(int node, vector<vector<int>>& graph, vector<bool>& vis) {
        int cnt = 1;
        int sod = 0;
        vis[node] = true;
        for(auto ch: graph[node]) {
            if(!vis[ch]) {
                pair<int, int> p = dfs(ch, graph, vis);
                cnt += p.first;
                sod += p.second + p.first;
            }
        }
        vis[node] = false;
        SOD[node] = sod;
        childs[node] = cnt;
        return {cnt, sod};
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this -> childs.resize(n, 0);
        this -> dist.resize(n, 0);
        this -> SOD.resize(n, 0);
        vector<vector<int>> graph(n);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        dfs(0, graph, vis);
        int curr = 0;
        for(auto d: dist) curr += d;
        vector<int> ans(n, 0);
        queue<pair<int, int>> q;
        vis[0] = true;
        ans[0] = SOD[0];
        for(auto node:graph[0]) q.push({node, 0});
        while(!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            ans[node] = SOD[node] + ((n - childs[node]) + SOD[par] - SOD[node] - childs[node]);
            SOD[node] = ans[node];
            vis[node] = true;
            for(auto ch:graph[node]) {
                if(!vis[ch]) q.push({ch, node});
            }
        }
        return ans;
    }
};
