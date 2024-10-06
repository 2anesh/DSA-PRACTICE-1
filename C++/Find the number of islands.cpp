class Solution {
  public:
    int n, m, res = 0, dxy[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    bool valid( int x, int y ){return x >= 0 && x < n && y >= 0 && y < m;};
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size(); res = 0;
        bool vis[n+1][m+1]; memset(vis, false, sizeof(vis));
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<m; j++ ){
                if ( grid[i][j] == '1' && !vis[i][j] ){
                    queue<pair<int,int>> q; res++;
                    q.push({i,j}); vis[i][j] = true;
                    while ( !q.empty() ){
                        int k = q.size();
                        while ( k-- ){
                            pair<int,int> p = q.front(); q.pop();
                            int a = p.first, b = p.second;
                            for ( int k = 0; k<8; k++ ){
                                int x = a + dxy[k][0], y = b + dxy[k][1];
                                if ( valid(x,y) && grid[x][y] == '1' && !vis[x][y] ){
                                    q.push({x,y}); vis[x][y] = true;
                                }
                            }
                        }
                    }
                }
            }
        } return res;
    }
};
