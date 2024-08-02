class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int ct = 0; 
        int i = 0;
        int j = 0;
        int current1 = 0;
        int ans = Integer.MAX_VALUE;
        for (int k : nums) {
            if (k == 1) ct++;
        }
        int[] num = new int[n * 2];
        for (int k = 0; k < n; k++) {
            num[k] = nums[k];
            num[k + n] = nums[k];
        }        
        for (j = 0; j < ct; j++) {
            if (num[j] == 1) current1++;
        }    
        while (j < 2 * n) {
            if (num[j] == 1) current1++;
            if (num[i] == 1) current1--;
            ans = Math.min(ans, ct - current1);
            j++;
            i++;
        }
        return ans;
    }
}
