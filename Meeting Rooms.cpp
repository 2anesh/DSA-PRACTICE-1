class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        int maxi = 0;
        for (auto it : arr) {
            maxi = max(maxi, it[1]);
        }
        
        int* freq = new int[maxi + 1]();
        for (auto it : arr) {
            freq[it[0]]++;
            freq[it[1]]--;
        }
        
        for (int i = 1; i <= maxi; i++) {
            freq[i] += freq[i - 1];
            if (freq[i] > 1) {
                delete[] freq;
                return false;
            }
        }
        
        delete[] freq;
        return true;
    }
};
