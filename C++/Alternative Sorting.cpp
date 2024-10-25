class Solution {
  public:
   vector<int> alternateSort(vector<int>& arr) {
    int n = arr.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    for (int i = 0; i < n; i+=2) {
        arr[i] = pq.top();
        pq.pop();
    }
    int i = (n % 2 == 0) ? (n-1) : (n-2);
    while (i > 0) {
        arr[i] = pq.top();
        pq.pop();
        i -= 2;
    }
    return arr;
}
};
