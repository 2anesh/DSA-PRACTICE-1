class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    int max_seen = -1; 
    int chunk_count = 0; 
    for (int i = 0; i < n; ++i) {
        max_seen = max(max_seen, arr[i]); 
        if (max_seen == i) { 
            chunk_count++; 
        }
    }

    return chunk_count;        
    }
};
