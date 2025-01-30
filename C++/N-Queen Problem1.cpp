class Solution {
  public:
    vector<vector<int>> res;

    void solve(int col, int n, vector<vector<int>> &board, vector<int> &temp, vector<int> &leftRow, vector<int> &lowDiag, vector<int> &upDiag)
    {
        if(col==n){
            res.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowDiag[row+col]==0 && upDiag[n-1+col-row]==0){
                board[row][col]=1;
                leftRow[row]=1;
                lowDiag[row+col]=1;
                upDiag[n-1+col-row]=1;
                temp.push_back(row+1);
                
                solve(col+1,n,board,temp,leftRow,lowDiag,upDiag);
                
                temp.pop_back();
                board[row][col]=0;
                leftRow[row]=0;
                lowDiag[row+col]=0;
                upDiag[n-1+col-row]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n,vector<int>(n));
        vector<int> temp;
        vector<int> leftRow(n), lowDiag(2*n-1), upDiag(2*n-1);
        solve(0,n,board,temp,leftRow,lowDiag,upDiag);
        return res;
    }
};
