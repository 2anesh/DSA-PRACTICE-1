class Solution {
public:

int dfs(int par,int node,vector<vector<int>>& G,int& val){
    int ans = 0;
    pair<int,int> S = {0,0}; // S[0] > S[1] 
    for(auto it : G[node]){
        if(it != par){
            int p = 1 + dfs(node,it,G,val);
            if(p >= S.first){
                S.second = S.first;
                S.first  = p;
            }
            else if(p >= S.second){
                S.second = p;
            }
            ans = max(ans , p);
        }
    }
    val = max(val , S.first + S.second);
    return ans;
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

   int n = 0;
   int m = 0;
   for(auto it : edges1){
      n = max(n , it[0]);
      n = max(n,  it[1]);
   }
    for(auto it : edges2){
      m = max(m , it[0]);
      m = max(m,  it[1]);
   }
   n++;
   m++;

   vector<vector<int>> G1(n);
   vector<vector<int>> G2(m);

   for(auto it : edges1){
      G1[it[0]].push_back(it[1]);
      G1[it[1]].push_back(it[0]);
   }
   for(auto it : edges2){
      G2[it[0]].push_back(it[1]);
      G2[it[1]].push_back(it[0]);
   }

   int val = 0;
   dfs(-1,0,G1,val);
   int a = val; 
   
   val = 0;
   dfs(-1,0,G2,val);
   int b = val;

   int ans = (a + 1)/2 + (b + 1)/2 + 1;
   ans = max(ans , a);
   ans = max(ans , b);
   return ans; 
}


};
