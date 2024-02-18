class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        if(n <= 0 or meetings.size() == 0) return -1;
        sort(meetings.begin(), meetings.end());
        auto cmp = [](vector<long long> &a, vector<long long> &b){ 
            if(b[1] == a[1])
                return a[2] > b[2];
            return a[1] > b[1];
        };
        priority_queue<vector<long long>, vector<vector<long long>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> hashmap;
        unordered_set<int> rooms;
        pq.push({meetings[0][0], meetings[0][1], 0});
        rooms.insert(0);
        for(int i = 1; i < meetings.size(); i++) {
            while(!pq.empty() and pq.top()[1] <= meetings[i][0]) {
                auto curr = pq.top();
                rooms.erase(curr[2]);
                hashmap[curr[2]]++;
                pq.pop();
            }
            if(pq.size() < n) {
                for(int j = 0 ; j < n; j++) {
                    if(!rooms.count(j)) {
                        rooms.insert(j);
                        pq.push({meetings[i][0], meetings[i][1],j});
                        break;
                    }
                }
                continue;
            }
            auto curr = pq.top();
            hashmap[curr[2]]++;
            pq.pop();
            rooms.erase(curr[2]);
            auto diff = curr[1] - meetings[i][0];
            pq.push({curr[0],meetings[i][1]+diff,curr[2]});
        }
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            hashmap[curr[2]]++;
        }
        int res = 0;
        int maxv = 1;

        for(auto i: hashmap) {
            if(i.second >= maxv) {
                if(maxv == i.second) {
                    if(res > i.first)
                        res = i.first;
                    continue;
                }
                maxv = i.second;
                res = i.first;
            }
        }
        return res;
    }
};
