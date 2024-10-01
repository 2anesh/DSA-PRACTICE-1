class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] remainderCount = new int[k];       
        for (int num : arr) {
            int rem = num % k;            
            if (rem < 0) {
                rem += k;
            }
            remainderCount[rem]++;
        }       
        for (int i = 1; i < k; i++) {            
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }     
        return remainderCount[0] % 2 == 0;
    }
}
