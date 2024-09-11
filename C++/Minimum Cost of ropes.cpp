class Solution {
  public:
    long long minCost(vector<long long>& arr) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(long long i : arr) pq.push(i);
        long long sum = 0;
        while(pq.size() != 1){
            int r1 = pq.top(); pq.pop();
            int r2 = pq.top(); pq.pop();
            sum += r1 + r2;
            pq.push(r1+r2);
        }
        return sum;
    }
};
