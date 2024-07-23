class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> relation;
        vector<int> res;
        for (int num : nums) {
            relation[num]++;
        }
        vector<pair<int, int>> freqVec(relation.begin(), relation.end());
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        for (auto& p : freqVec) {
            for (int i = 0; i < p.second; ++i) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
