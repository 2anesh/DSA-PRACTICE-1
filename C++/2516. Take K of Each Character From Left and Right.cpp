class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> total_count(3, 0);
        for (char c : s) {
            total_count[c - 'a']++;
        }
        for (int count : total_count) {
            if (count < k) return -1;
        }
        int n = s.size();
        vector<int> current_count(3, 0); 
        int max_window_size = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            current_count[s[right] - 'a']++;
            while (current_count[0] > total_count[0] - k ||
                   current_count[1] > total_count[1] - k ||
                   current_count[2] > total_count[2] - k) {
                current_count[s[left] - 'a']--;
                left++;
            }
            max_window_size = max(max_window_size, right - left + 1);
        }
        return n - max_window_size;
    }
};
