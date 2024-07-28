class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        vector<int> first(n + 1, INT_MAX), second(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 1}); 
        first[1] = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int currT = p.first;
            for (auto adjNode : adj[node]) {
                int nextT = currT + time;
                if ((currT / change) % 2 ==
                    1) { 
                    nextT +=
                        (change - (currT % change));                                                  
                }
                if (nextT < first[adjNode]) { 
                    first[adjNode] = nextT;
                    pq.push({nextT, adjNode});
                }
                if (first[adjNode] < nextT &&
                    nextT < second[adjNode]) { 
                    second[adjNode] = nextT;
                    pq.push({second[adjNode], adjNode});
                }
            }
        }
        return second[n];
    }
};
