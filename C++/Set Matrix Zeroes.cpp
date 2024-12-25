class Solution {
  public:
    void row_change(vector<vector<int>>&store, int row, int col){
        
        for(int i = 0;i<store[row].size();i++) {
            store[row][i] = 0;
        }
    }
    
    void col_change(vector<vector<int>>&store, int row, int col){
        for(int i = 0;i<store.size();i++) {
            store[i][col] = 0;
        }
    }
    
    void setMatrixZeroes(vector<vector<int>> &mat) {
        
        vector<vector<int>>store = mat;
        
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(mat[i][j] ==  0){
                    row_change(store, i, j);
                    col_change(store, i, j);
                }
            }
        }
        mat =  store;
    }
};
