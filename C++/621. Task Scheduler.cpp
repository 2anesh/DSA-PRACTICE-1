class Compare{
public:
bool operator()(pair<char, int> a, pair<char, int> b){
    return (a.second < b.second) || (a.second == b.second && a.first > b.first);
}
};
class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
    if(n == 0) return tasks.size();
    unordered_map<char, int> mp;
    int res = 0;
    for(auto c : tasks){mp[c]++;}
    vector<char> vec;
    priority_queue< pair<char, int> , vector< pair<char, int> >, Compare > pq;
    for(auto m : mp){pq.push(m);}

    int len = tasks.size();
    while(!pq.empty()){
        vector< pair<char, int> > vec;
        for(int i = 0; i <= n; ++i){//under any circumstance, the distance between the same char should always be n.
            if(len == 0) {return res;}
            if(pq.empty()) {
                res++;
            }else{
                auto q = pq.top();
                pq.pop();
                res++;
                if(--q.second > 0){
                    vec.push_back(q);
                }
                len--;
            }
        }
        for(auto v : vec){
            pq.push(v);
        }
    }
    return res;
}
};
