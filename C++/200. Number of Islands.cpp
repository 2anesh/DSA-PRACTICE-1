class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i + 1 < grid.size() && grid[i+1][j] == '1' && !visited[i+1][j]){
                visited[i+1][j] = 1;
                q.push({i+1, j});
            }
            if(j + 1 < grid[0].size() && grid[i][j+1] == '1' && !visited[i][j+1]){
                visited[i][j+1] = 1;
                q.push({i, j+1});
            }
            if(i - 1 >= 0 && grid[i-1][j] == '1' && !visited[i-1][j]){
                visited[i-1][j] = 1;
                q.push({i-1, j});
            }
            if(j - 1 >= 0 && grid[i][j-1] == '1' && !visited[i][j-1]){
                visited[i][j-1] = 1;
                q.push({i, j-1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    bfs(grid, visited, i , j);
                }
            }
        }
        return count;
    }
};
