class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq; 
        if (a) pq.emplace(a, 'a'); 
        if (b) pq.emplace(b, 'b'); 
        if (c) pq.emplace(c, 'c'); 
        string ans; 
        while (pq.size()) {
            auto [x, c] = pq.top(); pq.pop(); 
            if (ans.size() >= 2 && ans.back() == c && *(ans.rbegin()+1) == c) 
                if (pq.size()) {
                    auto [xx, cc] = pq.top(); pq.pop(); 
                    ans.push_back(cc); 
                    if (xx-1) pq.emplace(xx-1, cc); 
                    pq.emplace(x, c); 
                } else break; 
            else {
                ans.push_back(c); 
                if (x-1) pq.emplace(x-1, c); 
            }
        }
        return ans; 
    }
};
