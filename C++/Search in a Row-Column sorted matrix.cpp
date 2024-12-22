class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        for (int i=0;i<mat.size();i++){
            int low=0;
            int high=mat[0].size()-1;
            while (low<=high){
                int mid=(low+high)/2;
                if (mat[i][mid]<x){
                    low=mid+1;
                }else if(mat[i][mid]>x){
                    high=mid-1;
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};
