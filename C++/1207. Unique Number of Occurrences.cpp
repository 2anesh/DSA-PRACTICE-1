class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> p;
        int q = arr.size();
        for(int i = 0; i < q; i++)
        {
            p[arr[i]]++;
        }
        unordered_set<int> ans;
        for(auto it = p.begin(); it != p.end(); it++)
        {
            if(ans.find(it->second) != ans.end())
                return false;
            ans.insert(it->second);
        }
        return true;
    }
};
