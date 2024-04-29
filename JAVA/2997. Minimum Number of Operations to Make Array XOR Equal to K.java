class Solution {
    public int minOperations(int[] nums, int k) {
        int xor = 0; 
        for (int num: nums) xor = (num ^ xor);
        xor = k ^ xor; 
        int ans = 0;
        while (xor != 0) {
            if ((xor&1)==1) ans++;
            xor = xor >> 1;
        }
        return ans;
    }
}
