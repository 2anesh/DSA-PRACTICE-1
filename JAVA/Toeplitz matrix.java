class Solution{
    boolean isToeplitz(int mat[][]) {
        int n = mat[0].length;
        for(int i=0 ; i<mat.length ; i++){
            for(int j=0 ; j<n ; j++){
                if(i-1 >= 0 && j-1 >= 0 && mat[i-1][j-1] != mat[i][j])
                    return false;
                if(i+1 < mat.length && j+1 < n && mat[i+1][j+1] != mat[i][j])
                    return false;
            }
        }
        return true;
    }
}
