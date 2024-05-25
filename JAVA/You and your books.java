class Solution {
    long max_Books(int arr[], int n, int k) {
        long ans = 0;
        long sum = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= k){
                sum += arr[i];
                ans = Math.max(ans, sum);
            } else {
                sum = 0;
            }
        }
        return ans;
    }
}
