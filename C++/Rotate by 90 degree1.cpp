class Solution {
  public:
    void rotateby90(vector<vector<int>>& mat) {
        for(auto &vec:mat){
            reverse(vec.begin(),vec.end());
        }
        for(int i=0;i<mat.size();i++){
            for(int j=i;j<mat[0].size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }  
        }
};
