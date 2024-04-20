class Solution {
public:
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};
    int colSize = 0,rowSize = 0;
    int lastRow = 0, lastCol = 0;
    bool isValid(int x, int y) {
        if (x >= 0 && x < rowSize && y >= 0 && y < colSize) {
            return true;
        }
        return false;
    }
    vector<int> solve(int i, int j, vector<vector<int>>& land, vector<vector<int>>& visited) {
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (isValid(x, y) && visited[x][y] == 1) {
                visited[x][y] = 0;
                lastRow = max(lastRow, x);
                lastCol = max(lastCol, y);
                solve(x, y, land, visited);
            }
        }
        return {lastRow, lastCol};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        colSize = land[0].size();
        rowSize = land.size();
        vector<vector<int>> ans;
        vector<vector<int>> visited;
        visited.insert(visited.end(), land.begin(), land.end());
        vector<int> store;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (land[i][j] == 1 && visited[i][j] == 1) {
                    visited[i][j] = 0;
                    lastRow = i, lastCol = j;
                    store.insert(store.end(), {i,j});
                    vector<int> coor = solve(i, j, land, visited);
                    store.insert(store.end(), coor.begin(), coor.end());
                    ans.push_back(store);
                    store.clear();
                }
            }
        }
        return ans;
    }
};
