class Solution {
  public:
    int countTriplets(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int sum = arr[i] + arr[j];
            int third = target - sum;
            int low = j + 1, high = arr.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == third) {
                    int left = mid, right = mid;
                    while (left >= j + 1 && arr[left] == third) left--;
                    while (right <= arr.size() - 1 && arr[right] == third) right++;
                    cnt += (right - left - 1);
                    break;
                } else if (arr[mid] < third) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
    return cnt;
}
};
