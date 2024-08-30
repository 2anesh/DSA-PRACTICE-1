class Solution{
public:
    void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                temp.push_back(j + 1); 
            }
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;
    while (y >= 0) {
        if (board[x][y] == 1)
            return false;
        y--;
    }
    x = row;
    y = col;
    while (y >= 0 && x >= 0) {
        if (board[x][y] == 1)
            return false;
        y--;
        x--;
    }
    x = row;
    y = col;
    while (y >= 0 && x < n) {
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, board, ans, n);
    sort(ans.begin(), ans.end());
    return ans;
  }
};
