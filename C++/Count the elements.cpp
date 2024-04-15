class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        vector<int> ans;
        sort(b.begin(), b.end());
        for(auto i: query) {
            int ele = a[i], count = upper_bound(b.begin(), b.end(), ele) - b.begin();
            ans.push_back(count);
        }
        return ans;
    }
};
