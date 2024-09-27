class Solution {
  public:
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        unordered_map<int,int> f; priority_queue<int> pq; vector<int> res;
        for ( int i = 0; i<k-1; i++ ) pq.push(arr[i]), f[ arr[i] ]++;
        for ( int i = k-1; i<arr.size(); i++ ){
            pq.push(arr[i]); f[ arr[i] ]++;
            while ( !pq.empty() && f[ pq.top() ] == 0 ) pq.pop();
            pq.push(arr[i-k+1]-1); f[ arr[i-k+1] ]--;
            res.push_back(pq.top());
        } return res;
    }
};
