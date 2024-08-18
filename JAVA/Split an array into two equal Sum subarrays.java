class Solution {
    public boolean canSplit(int arr[]) {
        int arrSum = 0, sum = 0, n = arr.length;
        for(int i=0; i < n; i++) {
            arrSum += arr[i];
        }
        for(int i=0; i < n; i++) {
            sum += arr[i];
            if(sum * 2 == arrSum) {
                return true;
            }
        }
        return false;
    }
}
