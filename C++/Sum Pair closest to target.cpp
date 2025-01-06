class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int max_sum = INT_MAX;
        int absd_max = INT_MIN;
        int p = -1, q = -1;
        int i = 0, j = n - 1;

        while (i < j) {
            int a = arr[i];
            int b = arr[j];
            int sum = a + b;
            int abs_diff = abs(a - b);

            if (abs(target - sum) < abs(target - max_sum) ||
                (abs(target - sum) == abs(target - max_sum) && abs_diff > absd_max)) {
                max_sum = sum;
                absd_max = abs_diff;
                p = a;
                q = b;
            }

            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        if (p == -1 || q == -1) return {};
        return {p, q};
    }
};
