class Solution {
    List<Integer> or_list = new ArrayList<>();
    private void helper(int[] nums, int sum, int idx) {
        if (idx == nums.length) {
            or_list.add(sum);
            return;
        }
        int val = sum | nums[idx];
        helper(nums, val, idx + 1);
        helper(nums, sum, idx + 1);
    }
    public int countMaxOrSubsets(int[] nums) {
        helper(nums, 0, 0);
        Collections.sort(or_list, Collections.reverseOrder());
        int max = or_list.get(0);
        int res = 0;
        for (var l : or_list) {
            if (max == l)
                res++;
            else
                break;
        }
        return res;
    }
}
