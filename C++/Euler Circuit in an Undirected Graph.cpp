class Solution {
public:
   void dfs(int i,vector<int>adj[], vector<bool>& vis){
       if(vis[i])return ;
       vis[i] = true;
       for(auto j:adj[i]){
           if(!vis[j])dfs(j,adj,vis);
       }
   }
   bool isconnected(vector<int> adj[],int v){
       vector<bool>vis(v,false);
       int first = 0;
       for(int i=0;i<v;i++){
           if(adj[i].size()==0)vis[i] = true;
       }
       for(int i=0;i<v;i++){
           if(adj[i].size()!=0){
               first = i;
               break;
           }
       }
       dfs(first,adj,vis);
       for(auto i:vis){
           if(!i)return false;
       }
       return true;
   }
	bool isEularCircuitExist(int v, vector<int>edg[]){
	    if(!isconnected(edg,v))return false;
	    int odd = 0;
	    for(int i=0;i<v;i++){
	        if(edg[i].size() & 1)odd++;
	    }
	    if(odd >= 1)return false;
	    return true;
	}
};
