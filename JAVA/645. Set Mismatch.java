class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] result = new int[2];
        Arrays.sort(nums);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                result[0] = nums[i];
                break;
            }
        }
        int expectedSum = n * (n + 1) / 2;
        int actualSum = Arrays.stream(nums).sum();
        result[1] = expectedSum - (actualSum - result[0]);
        return result;
    }
}
