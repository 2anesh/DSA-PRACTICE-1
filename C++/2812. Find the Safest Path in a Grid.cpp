class Solution {
public:
  vector<pair<int,int>>moves = {{-1,0},{1,0},{0,-1},{0,1}};
  vector<pair<int,int>>mv = {{0,1},{1,0}};
     bool can_reach(int mid, vector<vector<int>>& safe){         
      if(safe[0][0] < mid) return false;
      int n = safe.size();
      vector<vector<bool>>vis(n, vector<bool>(n,0));
      queue<pair<int,int>>q;
      q.push({0,0});
      while(!q.empty()){
        pair<int,int> fr = q.front();
        int i = fr.first;
        int j = fr.second;
        if(i==n-1 and j==n-1  ) return true;
        q.pop();
        for(auto it: moves ){
           int r = it.first+i;
           int c = it.second+j;
           if(r>=0 and r<n and c>=0 and c<n and safe[r][c] >= mid and vis[r][c] == 0){
             q.push({r,c});
             vis[r][c] = 1;
           }
        }
      }
      return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1) return 0;
        vector<vector<int>>safe(n,vector<int>(n));
        vector<vector<int>>vis(n, vector<int>(n,0));
        queue<pair<pair<int,int>, int>>q; 
        for(int i=0;i<n;i++){
          for(int j =0;j<n;j++){
            if(grid[i][j] == 1){
              q.push({{i,j},0});
              vis[i][j] = 1;
            }
          }
        }
        while(!q.empty()){
          pair<pair<int,int>,int>fr = q.front();
          q.pop();
          for(auto it: moves){
              int row = fr.first.first + it.first;
              int col = fr.first.second+it.second;
              int cnt = fr.second;
              if(row>=0 and row<n and col>=0 and col<n and
               grid[row][col] == 0 and vis[row][col]== 0){
                 q.push({{row,col},cnt+1});
                 vis[row][col] = 1;
                 safe[row][col] = cnt+1;
               } 
          }
        }
        int low = 0,high = 1e9, ans = 0;
        while(low<=high){
          int mid = low+(high-low)/2;
          if(can_reach(mid, safe)){
            ans =  max(mid, ans);
            low = mid+1;
          }
          else 
           high = mid-1;
        }
        return ans;
    }
};
