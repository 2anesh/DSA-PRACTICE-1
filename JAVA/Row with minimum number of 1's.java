class Solution {
    int minRow(int n, int m, int a[][]) {
    
        int min=Integer.MAX_VALUE;
        int row=0;
        for(int i=0;i<n;i++){
            int cnt1=0;
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    cnt1++;
                }
            }
            if(min>cnt1){
                min=cnt1;
                row=i+1;
            }
        }
        return row;
    }
};
