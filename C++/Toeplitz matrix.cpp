bool isToeplitz(vector<vector<int>>& mat) {
     for(int i=1; i<mat.size();i++){
            for(int j=1;j<mat[i].size();j++){
            if(mat[i][j]!=mat[i-1][j-1]) {
            return false;
            }
            }
        }
        return true;
}
