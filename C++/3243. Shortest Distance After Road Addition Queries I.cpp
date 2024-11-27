class Solution {
public:
    int bfs(vector<vector<int>>& graph) {
        int destNode = graph.size() - 1;
        queue<int> q;
        unordered_set<int> s;
        q.push(0);
        s.insert(0);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int front = q.front();
                q.pop();
                if (front == destNode)
                    return level;
                for (const int& n : graph[front]) {
                    if (s.find(n) == s.end()) {
                        q.push(n);
                        s.insert(n);
                    }
                }
            }
            level++;
        }
        return level;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }
        int q = queries.size();
        vector<int> res(q);
        for (int i = 0; i < q; i++) {
            graph[queries[i][0]].push_back(queries[i][1]);
            res[i] = bfs(graph);
        }
        return res;
    }
};
