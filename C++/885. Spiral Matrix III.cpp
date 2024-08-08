class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps = 1;  
        int dirIndex = 0;          
        int r = rStart;
        int c = cStart;        
        while (result.size() < rows * cols) {
            for (int i = 0; i < 2; ++i) {  
                for (int j = 0; j < steps; ++j) {
                    r += directions[dirIndex][0];
                    c += directions[dirIndex][1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                dirIndex = (dirIndex + 1) % 4;  
            }
            steps++;  
        }        
        return result;
    }
};
