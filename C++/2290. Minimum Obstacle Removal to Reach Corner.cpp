class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool check(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m) return false;
        return true;
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dist[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dist[i][j]=1e9;
            }
        }
        deque<pair<int,int>> dq;
        dq.push_back({0,0});
        dist[0][0]=grid[0][0];
        while(!dq.empty()){
            auto it = dq.front();
            dq.pop_front();
            for(int i=0; i<4; i++){
                int x = it.first+dx[i], y = it.second+dy[i];
                if(check(x,y,n,m)){
                   if(dist[x][y]>dist[it.first][it.second]+grid[x][y]){
                       dist[x][y] = dist[it.first][it.second]+grid[x][y];
                       if(grid[x][y]){
                           dq.push_back({x,y});
                       }else{
                           dq.push_front({x,y});
                       }
                   } 
                }
            }
        }
        return dist[n-1][m-1];
    }
};
