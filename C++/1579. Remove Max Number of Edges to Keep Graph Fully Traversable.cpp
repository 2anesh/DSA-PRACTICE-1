class DSU{  
   public : 
        vector<int> parent;
        vector<int> rank;
        int components;
    DSU(int n){  
        parent.resize(n+1);
        rank.resize(n+1,0);
        components = n;
        for(int i =1;i<=n;i++)
         parent[i] = i;
    }
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    void unionn(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent]) 
        parent[y_parent] = x_parent;
        else if(rank[x_parent]<rank[y_parent]) 
        parent[x_parent] = y_parent;
        else {
           parent[x_parent] = y_parent;
           rank[y_parent]++;
       }
       components--;
    }
   bool isSigleComponet(){
        return components==1;
   }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
     DSU Alice(n);
     DSU Bob(n);
     auto cmp = [&](vector<int>&v1,vector<int>&v2){
         return v1[0]>v2[0]; // desending order
     };
     sort(edges.begin(),edges.end(),cmp);
     int edgesCount = 0;
     for(auto &x:edges){
         int type = x[0];
         int u = x[1];
         int v = x[2];
         bool flag = false;
         if(type==3){
            if(Alice.find(u) !=Alice.find(v)){
               Alice.unionn(u,v);
               flag = true;
            }
             if(Bob.find(u) !=Bob.find(v)){
               Bob.unionn(u,v);
               flag = true;
            }
           if(flag) edgesCount++;
         } 
         if(type==1)
             if(Alice.find(u) !=Alice.find(v)){
                Alice.unionn(u,v);
                edgesCount++;
            }
         if(type==2)
               if(Bob.find(u) !=Bob.find(v)){
                Bob.unionn(u,v);
                 edgesCount++;
            }
     }
        if(Alice.isSigleComponet()==true && Bob.isSigleComponet()==true)  return edges.size()-edgesCount;
        return -1;
    }
};
