class heap {
public:
    void heapify(vector<int> &arr, int i, int n) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;        
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }        
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, largest, n);
        }
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return {};
        }
        vector<int> sorted(arr.begin(), arr.end());
        unordered_map<int, int> rank;
        int k = 1;
        heapsort(sorted);
        for (int num : sorted) {
            if (rank.find(num) == rank.end()) {
                rank[num] = k++;
            }
        }
        vector<int> res;
        for (int val : arr) {
            res.push_back(rank[val]);
        }

        return res;
    }
private:
    void heapsort(vector<int>& sorted) {
        int n = sorted.size();
        heap ob;        
        for (int i = n / 2 - 1; i >= 0; i--) {
            ob.heapify(sorted, i, n);
        }
        for (int i = n - 1; i >= 0; i--) {
            swap(sorted[0], sorted[i]);
            ob.heapify(sorted, 0, i);  
        }
    }
};
