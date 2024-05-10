class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = size(arr); 
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq; 
        for (int i = 0; i < n-1; ++i) 
            pq.push({(double) arr[i]/arr[n-1], {i, n-1}}); 
        
        int i = 0, j = 0; 
        while (k--) {
            auto elem = pq.top(); pq.pop(); 
            i = elem.second.first;
            j = elem.second.second; 
            if (i < j-1) pq.push({(double) arr[i]/arr[j-1], {i, j-1}}); 
        }
        return {arr[i], arr[j]}; 
    }
};
