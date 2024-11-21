class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> v(m,vector<char>(n,'0'));
        int a=guards.size();
        for(int i=0;i<a;i++){
              v[guards[i][0]][guards[i][1]]='G';
        }
        int b=walls.size();
        for(int i=0;i<b;i++){
              v[walls[i][0]][walls[i][1]]='W';
        }
        int ct(0);
        for(int i=0;i<a;i++){
              int x=guards[i][0];
              int y=guards[i][1];
              int s=x+1,o=x-1,ss=y+1,oo=y-1;
              while(s<m && (v[s][y]!='W' && v[s][y]!='G')){
                  if(v[s][y]=='0') ct++;
                  v[s][y]='1';
                  s++;
              }
              while(o>=0 && (v[o][y]!='W' && v[o][y]!='G')){
                  if(v[o][y]=='0') ct++;
                  v[o][y]='1';
                  o--;
              }
              while(ss<n && (v[x][ss]!='W' && v[x][ss]!='G')){
                  if(v[x][ss]=='0') ct++;
                  v[x][ss]='1';
                  ss++;
              }
              while(oo>=0 && (v[x][oo]!='W' && v[x][oo]!='G')){
                  if(v[x][oo]=='0') ct++;
                  v[x][oo]='1';
                  oo--;
              }
        }
        return m*n-a-b-ct;
    }
};
