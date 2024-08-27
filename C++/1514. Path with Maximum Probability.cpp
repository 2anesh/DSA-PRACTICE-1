class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> maxProb(n);
        maxProb[start]=1.0;
        for(int i=0;i<n-1;i++){
            bool hasUpdated=false;
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                double pathProb=succProb[j];
                if(maxProb[u] * pathProb > maxProb[v]){
                    maxProb[v]=maxProb[u] * pathProb;
                    hasUpdated=true;
                }
                if(maxProb[v] * pathProb > maxProb[u]){
                    maxProb[u]=maxProb[v] * pathProb;
                    hasUpdated=true;
                }
            }
            if(!hasUpdated){
                break;
            }
        }
        return maxProb[end];
    }
};
