class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end()); 
        vector<pair<int, int>> aug; 
        for (int i = 0; i < queries.size(); ++i) aug.emplace_back(queries[i], i); 
        sort(aug.begin(), aug.end()); 
        vector<int> ans(queries.size()); 
        int prefix = 0, ii = 0; 
        for (auto& [x, i] : aug) {
            for (; ii < items.size() && items[ii][0] <= x; ++ii)  
                prefix = max(prefix, items[ii][1]); 
            ans[i] = prefix; 
        }
        return ans; 
    }
};
