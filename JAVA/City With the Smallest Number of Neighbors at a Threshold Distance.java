class Solution {
      int findCity(int n, int m, int[][] e,int d)
      {
          int[][] ma=new int[n][n];
          for(int[] r:ma){
          Arrays.fill(r,10001);}
          for(int i=0;i<n;i++){
              ma[i][i]=0;
          }
          for(int[]it:e){
              ma[it[0]][it[1]]=ma[it[1]][it[0]]=it[2];
          }
          for(int k=0;k<n;k++){
              for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                      ma[i][j]=Math.min(ma[i][j],ma[i][k]+ma[k][j]);
                  }
              }
          }
          int ans=-1;
          int ne=n+1;
          for(int i=0;i<n;i++){
              int cnt=0;
              for(int j=0;j<n;j++){
                  if(ma[i][j]<=d)cnt++;
              }
              if(cnt<=ne){
                  ne=cnt;
                  ans=i;
              }
          }
          return ans;
      
      }
}
