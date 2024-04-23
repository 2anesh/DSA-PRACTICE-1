class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 2) {
            vector<int> result;
            result.push_back(0);
            if (n == 2) result.push_back(1);
            return result;
        }
        vector<vector<int>> graph (n);
        for(vector<int> & edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);     
        }
        vector<int> height(n);
        height[0] = findHeight(graph, 0, -1, height);
        vector<int>  result;
        int u = 0;
        while(result.size() == 0) {
            int max1vertex, max1 = -2;
            int max2vertex, max2 = -2;
            for(int v : graph[u]) {
                if(max1 == -2) {
                    max1 = height[v];
                    max1vertex = v;
                }
                else if(height[v] >= max1) {
                    max2 = max1;
                    max2vertex = max1vertex;
                    max1 = height[v];
                    max1vertex = v;
                }
                else if(max2 == -2 || height[v] > max2) {
                    max2 = height[v];
                    max2vertex = v;
                }
            }            
            if(max1 == max2) {      
                result.push_back(u);
            } 
            else if(max1 == max2 + 1) {    
                result.push_back(u);
                result.push_back(max1vertex);
            } 
            else {
                  height[u] = (max2 == -2) ? 0 : max2 + 1;
                  u = max1vertex; 
             }        
        }
        return result;
    }    
    private:
        int findHeight(vector<vector<int>>& graph, int u, int parent, vector<int>& height) {
            int maxHeight = -1;
             for(int v : graph[u]) {
                 if(v != parent) {
                     height[v] = findHeight(graph, v, u, height);
                     maxHeight = max(maxHeight, height[v]);
                 }
             }
            return maxHeight + 1;
        }
};
