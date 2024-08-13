class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        combinationSum2(ans, candidates, target, 0,0, new ArrayList<Integer>());
        return ans;        
    }
    private void combinationSum2(List<List<Integer>> ans, int[] candidates, int target, int start, int sum, List<Integer> list) {
        if (sum == target) {
            ans.add(new ArrayList<>(list));
        }
        else if (sum > target) {
            return;
        }
        for (int j = start; j < candidates.length; j++) {
            if (j > start && candidates[j-1] == candidates[j]) {
                continue;
            }
            list.add(candidates[j]);
            combinationSum2(ans, candidates, target, j + 1, sum + candidates[j], list);
            list.remove(list.size()-1);
        }
    }
}
