class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), dir[5] = {-1, 0, 1, 0, -1}; 
        
        function<bool(int, int, int)> fn = [&](int i, int j, int k) {
            if (k == word.size()) return true; 
            if (0 <= i && i < m && 0 <= j && j < n && board[i][j] == word[k]) {
                char temp = board[i][j]; 
                board[i][j] = '#'; 
                for (int x = 0; x < 4; ++x) {
                    int ii = i + dir[x], jj = j + dir[x+1]; 
                    if (fn(ii, jj, k+1)) return true;
                }
                board[i][j] = temp; 
            }
            return false; 
        }; 
        
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (fn(i, j, 0)) return true; 
        return false; 
    }
};
