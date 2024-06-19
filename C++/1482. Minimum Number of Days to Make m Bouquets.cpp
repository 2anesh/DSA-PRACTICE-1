class Solution {
public:
    int possible(vector<int>& bloomDay, int k, int mid) {
        int tot = 0;
        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    tot++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return tot;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
           long long totalFlowers = (long long)m * (long long)k;
        if (bloomDay.size() < totalFlowers) {
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = high + 1;  
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, k, mid) >= m) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
