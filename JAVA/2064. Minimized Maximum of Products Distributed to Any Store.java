class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int l = 1, r = 100000;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(check(quantities, mid, n)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    private boolean check(int[] arr, int mid, int n) {
        int sum = 0;
        for(int num : arr) {
            sum += (num + mid - 1) / mid;
        }

        return sum > n;
    }
}
