class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int r = 0;
        int c = 0;
        int n = mat.size();
        vector<int> ans;
        int count = 0;
        while(count < n*n){
            ans.push_back(mat[r][c]);
            count++;
            if(count >= n*n) break;
            if(c + 1 < n){
                c++;
            }
            else{
                r++;
            }
            while(r < n - 1 && c > 0){
                ans.push_back(mat[r][c]);
                count++;
                r++;
                c--;
            }
            ans.push_back(mat[r][c]);
            count++;
            if(r + 1 < n){
                r++;
            }
            else{
                c++;
            }
            while(r > 0 && c < n - 1){
                ans.push_back(mat[r][c]);
                count++;
                r--;
                c++;
            }
        }
        return ans;
    }
};
