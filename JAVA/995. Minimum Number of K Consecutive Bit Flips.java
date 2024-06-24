class Solution {
    public int minKBitFlips(int[] nums, int k) {        
        int count = 0;
        int currFlipCount = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i - k >= 0 && nums[i - k] == 2) {
                currFlipCount -= 1;
            }
            if ((nums[i] + currFlipCount) % 2 == 0) {
                if (i + k > nums.length) return -1;
                count += 1;
                currFlipCount += 1;
                nums[i] = 2;
            }
        }
        return count;
    }
}
