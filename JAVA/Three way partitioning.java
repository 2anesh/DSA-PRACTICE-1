class Solution{
    public void threeWayPartition(int arr[], int a, int b) {
        int low = 0;
        int mid = 0;
        int high = arr.length - 1;
        while(mid <= high) {
            if(arr[mid] < a) {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
            } else if(arr[mid] >= a && arr[mid] <= b) {
                mid++;
            } else {
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
            }
        }
    }
}
