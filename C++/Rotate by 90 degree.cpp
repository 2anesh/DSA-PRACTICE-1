void rotate(vector<vector<int> >& mat) {
    int n=mat.size();
    int m=mat[0].size();
    int l=0,l2=m;
    vector<vector<int>> m1(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        l=0;
        l2--;
        for(int j=0;j<m;j++){
            m1[l][l2]=mat[i][j];
            l++;
        }
    }
    mat=m1;
}
