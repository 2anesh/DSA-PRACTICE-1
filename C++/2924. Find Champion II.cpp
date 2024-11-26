class Solution {
public:
    int parent[101];

void updateParent(int newParent, int node, vector<int> graph[]) {
    if (newParent == parent[node]) return;

    parent[node] = newParent;
    for(int x: graph[node]) {
        updateParent(newParent, x, graph);
    }
}

int findChampion(int n, vector<vector<int>> &edges)
{
    for (int i = 0; i < n; i++) parent[i] = i;
    vector<int> graph[n+1];
    for (auto &v: edges) {
        graph[v[0]].push_back(v[1]);
    }

    for (int i = 0; i < n; i++) {
        for (int x: graph[i]) {
            if (parent[x] != x) continue;
            updateParent(i, x, graph);
        }
    }

    int winner = parent[0];
    for (int i = 0; i < n; i++) {
        // cout << parent[i] << " " ;
        if (winner != parent[i]) return -1;
    }

    return winner;
}
};
