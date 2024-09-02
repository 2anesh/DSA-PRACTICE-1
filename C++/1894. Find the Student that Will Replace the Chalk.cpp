class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        k %= accumulate(begin(chalk), end(chalk), 0l); 
        for (int i = 0; i < size(chalk); ++i) {
            if ((k -= chalk[i]) < 0) return i; 
        }
        return -1; 
    }
};
