class Solution {
public:
    int n, m;
    void dfs(int node, vector<vector<int>>& stones, map<pair<int, int>, int>&mpp, 
    vector<bool>&vis,int &cnt, unordered_map<int, vector<int>>&mp1, 
    unordered_map<int, vector<int>>&mp2){
        vis[node]=1;
        int row=stones[node][0];
        int col=stones[node][1];
        cnt++;
        for(auto &it:mp1[row]){
            int x=mpp[{row, it}];
            if(!vis[x]){
                dfs(x, stones, mpp, vis, cnt, mp1, mp2);
            }
        }
        for(auto &it:mp2[col]){
            int x=mpp[{it, col}];
            if(!vis[x]){
                dfs(x, stones, mpp, vis, cnt, mp1, mp2);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {        
        map<pair<int, int>, int>mpp;
        n = 0; 
        m = 0;
        int e=stones.size();
        unordered_map<int, vector<int>>mp1, mp2;
        for(int i=0; i<e; i++){
            mpp[{stones[i][0], stones[i][1]}]=i;
            mp1[stones[i][0]].push_back(stones[i][1]);
            mp2[stones[i][1]].push_back(stones[i][0]);
            n=max(n, stones[i][0]);
            m=max(m, stones[i][1]);
        }
        n++;
        m++;
        vector<bool>vis(e, 0);
        int ans=0;
        for(int i=0; i<e; i++){
            int cnt=0;
            if(!vis[i]){
                dfs(i, stones, mpp, vis, cnt, mp1, mp2);
                ans+=(cnt-1);
            }
        }
        return ans;                
    }
};
