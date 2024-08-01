class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int rowStart = 0, colStart = 0, rowEnd = matrix.size()-1, colEnd = matrix[0].size()-1;
        vector<int> ans;
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for(int col=colStart; col<=colEnd; col++) {
                ans.push_back(matrix[rowStart][col]);
            }
            rowStart++;
            for(int row=rowStart; row<=rowEnd; row++) {
                ans.push_back(matrix[row][colEnd]);
            }
            colEnd--;
            for(int col=colEnd; col>=colStart && rowStart <= rowEnd; col--) {
                ans.push_back(matrix[rowEnd][col]);
            }
            rowEnd--;
            for(int row=rowEnd; row>=rowStart && colStart <= colEnd; row--) {
                ans.push_back(matrix[row][colStart]);
            }
            colStart++;
        }
        return ans;
    }
};
