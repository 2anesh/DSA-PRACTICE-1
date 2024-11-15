class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    int start = 0, end = n - 1;

    while(start < n - 1 && arr[start] <= arr[start + 1]) start++;

    if(start == n - 1) return 0;

    while(end >= start && arr[end] >= arr[end - 1]) end--;

    int result =min(n - 1 - start, end);

    int i = 0, j = end;
    while(i <= start && j < n) {
        if(arr[j] >= arr[i]) {
            result =min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }

    return result;
    }
};
