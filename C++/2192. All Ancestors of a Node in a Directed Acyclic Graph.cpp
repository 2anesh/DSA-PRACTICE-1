class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>indegree(n,0);
        for(auto i:adj){
            for(auto v:i.second){
                indegree[v]++;
            }
        }
        queue<int>pq;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                pq.push(i);
            }
        }
        vector<vector<bool>>table(n,vector<bool>(n,false));
        while(pq.size()>0){
            int front=pq.front();
            pq.pop();
            for(auto ngh:adj[front]){
                table[front][ngh]=true;
                for(int i=0;i<n;i++){
                    if(table[i][front]==true){
                        table[i][ngh]=true;
                    }
                }
                indegree[ngh]--;
                if(indegree[ngh]==0){
                    pq.push(ngh);
                }
            }
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(table[j][i]==true){
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};
