class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int>adj[n];
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        queue<int>q;
        visited[source]=true;
        q.push(source);
        while(q.empty()==false)
        {
            int u=q.front();
            q.pop();
            for(int x:adj[u])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return visited[destination];
    }
};
