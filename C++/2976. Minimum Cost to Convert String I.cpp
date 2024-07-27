class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        int INF = 1e9 + 7;
        vector<vector<int>> mincost(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) {
            mincost[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            mincost[u][v] = min(mincost[u][v], cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (mincost[i][k] < INF && mincost[k][j] < INF) {
                        mincost[i][j] = min(mincost[i][j], mincost[i][k] + mincost[k][j]);
                    }
                }
            }
        }
        long long totalCost = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                if (mincost[u][v] == INF) {
                    return -1; 
                }
                totalCost += mincost[u][v];
            }
        }
        return totalCost;
    }
};
