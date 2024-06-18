class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        cin.tie(nullptr)->sync_with_stdio(0);
        vector<pair<int, int>> jops;
        int sz_jops = difficulty.size(), sz_worker = worker.size(), ans = 0;
        for (int i = 0; i < sz_jops; ++i) {
            jops.push_back({difficulty[i], profit[i]});
        }
        sort(jops.begin(), jops.end());
        sort(worker.begin(), worker.end());
        priority_queue<int> maxHeap;
        for (int i = 0, j = 0; i < sz_worker; ++i) {
            while (j < sz_jops && jops[j].first <= worker[i]) {
                maxHeap.push(jops[j].second);
                j += 1;
            }
            if (!maxHeap.empty())
                ans += maxHeap.top();
        }
        return ans;
    }
};
