class Solution {
    int Maximize(int arr[]) {
        int MOD = 1000000007;
        Arrays.sort(arr);
        long ans = 0;
        int n = arr.length;
        for(int i = 0; i < n; i++){
            ans = (ans + (long) arr[i] * i) % MOD;
        }
        return (int) ans;
    }
}
