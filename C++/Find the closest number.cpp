class Solution {
public:
    int findClosest(int n, int k, int arr[]) {
        int ind = std::lower_bound(arr, arr + n, k) - arr;
        if (ind == 0) {
            return arr[0];
        }
        if (ind == n) {
            return arr[n - 1];
        }
        int leftElement = arr[ind - 1];
        int rightElement = arr[ind];
        int leftDiff = std::abs(leftElement - k);
        int rightDiff = std::abs(rightElement - k);
        if (leftDiff == rightDiff) {
            return rightElement;
        }
        return (leftDiff < rightDiff) ? leftElement : rightElement;
    }
};
