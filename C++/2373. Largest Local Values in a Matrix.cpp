class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int size = grid[0].size();
        vector<vector<int>> ans(size-2, vector<int>(size-2));
        for(int i = 1; i < size-1; i++)
        {
            for(int j = 1; j < size - 1; j++)
            {
                int x = 0;
                x = max(x, max(grid[i-1][j-1], max(grid[i-1][j], grid[i-1][j+1])));
                x = max(x, max(grid[i][j-1], max(grid[i][j], grid[i][j+1])));
                x = max(x, max(grid[i+1][j-1], max(grid[i+1][j], grid[i+1][j+1])));
                ans[i-1][j-1] = x;
            }
        }
        return ans;
    }
};
