class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        auto isConnected = [&](vector<vector<int>>& g) -> bool {
            vector<vector<int>> vis(rows, vector<int>(cols));
            int islands{0};
            auto dfs = [&](int r, int c, auto&& dfs_ref) -> void {
                if (r < 0 || r >= rows || c < 0 || c >= cols || g[r][c] == 0 || vis[r][c]) return;
                vis[r][c] = 1;
                dfs_ref(r + 1, c, dfs_ref); dfs_ref(r - 1, c, dfs_ref);
                dfs_ref(r, c + 1, dfs_ref); dfs_ref(r, c - 1, dfs_ref);
            };
            for (int r{0}; r < rows && islands < 2; ++r)
                for (int c{0}; c < cols && islands < 2; ++c)
                    if (g[r][c] == 1 && !vis[r][c]) {
                        dfs(r, c, dfs);
                        ++islands;                    }
            return islands == 1;
        };
        if (!isConnected(grid)) return 0;
        for (int r{0}; r < rows; ++r) {
            for (int c{0}; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    if (!isConnected(grid)) return 1;
                    grid[r][c] = 1;
                }
            }
        }
        return 2;
    }
};
