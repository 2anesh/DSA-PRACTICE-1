class Solution {
  public:
     int findExtra(int n, int arr1[], int arr2[]) {
        int low = 0, high = n-2;
        int res = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr1[mid] == arr2[mid]) {
                low = mid + 1;
            }
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return (res == -1) ? n-1 : res;
    }
};
