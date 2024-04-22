class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            int cntOne=0;
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    cntOne++;
                }
            }
            if(mini>cntOne){
                mini=cntOne;
                ans=i+1;
            }
        }
        return ans;
    }
};
