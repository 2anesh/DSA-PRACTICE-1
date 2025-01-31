class Solution {

    public:
    
    bool solved(vector<vector<int>> &mat, int r, int c, vector<vector<bool>> &rows, vector<vector<bool>> &cols,vector<vector<vector<bool>>> &box){
     
        if(c==9)
            return solved(mat,r+1,0,rows,cols,box);
        if(r==9)
            return true;
        // if vacant cell move forward
        if(mat[r][c]!=0)
            return solved(mat,r,c+1,rows,cols,box);
        for(int k=1; k<10; k++){
            // if k in row, col or box, don't put it in cell
            if(rows[r][k] || cols[c][k] || box[r/3][c/3][k] )
                continue;
            rows[r][k]= true;
            cols[c][k]= true;
            box[r/3][c/3][k]= true;
            // set cell as k
            mat[r][c]=k; 
            if(solved(mat,r,c+1,rows,cols,box))
                return true;
            rows[r][k]= false;
            cols[c][k]= false;
            box[r/3][c/3][k]= false;
            
        }
        mat[r][c]=0;
        return false;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        vector<vector<bool>> rows(9,vector<bool>(10,false));
        vector<vector<bool>> cols(9,vector<bool>(10,false));
        vector<vector<vector<bool>>> box(3,vector<vector<bool>>(3,vector<bool>(10,false)));
       for(int i=0; i<9; i++){
           for(int j=0; j<9; j++){
               int k = mat[i][j];
               if(k){
                   rows[i][k]= true;
                   cols[j][k]= true;
                   box[i/3][j/3][k]= true;
               }
           }
       }
       
        solved(mat,0,0,rows,cols,box);
 
    }
};
