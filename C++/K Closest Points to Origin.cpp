class Solution {
  public:
    static bool comp(pair<int, long long>& a, pair<int, long long>& b) {
        return a.second < b.second;
    }
    
    long long distance(int x, int y) {
        return (long long)x * x + (long long)y * y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, long long>> temp;
        
        for (int i=0; i<points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            long long dist = distance(x, y);
            temp.push_back({i, dist});
        }
        
        sort(temp.begin(), temp.end(), comp);
        vector<vector<int>> ans;
        
        for (int i=0; i<k; i++) {
            ans.push_back(points[temp[i].first]);
        }
        return ans;
    }
};
