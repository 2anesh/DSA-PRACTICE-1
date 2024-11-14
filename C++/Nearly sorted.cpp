class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n=arr.size(), idx=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<n; i++) {
            pq.push(arr[i]);
            if(pq.size()==k+1) {
                arr[idx++]=pq.top();
                pq.pop();
            }
        }
        while(!pq.empty()) {
            arr[idx++]=pq.top();
            pq.pop();
        }
    }
};

