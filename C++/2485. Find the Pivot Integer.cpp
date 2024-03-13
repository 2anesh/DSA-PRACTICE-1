class Solution {
public:
    int pivotInteger(int n) {
        int low = 1, high = n;
        int totalSum = (n * (n + 1)) / 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int currSum = (mid * (mid + 1)) / 2;
            if (totalSum - currSum + mid == currSum)
                return mid;
            else if (currSum < totalSum / 2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
