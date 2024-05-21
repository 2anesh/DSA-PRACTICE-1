class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(ans,temp,0,nums);
        return ans;
    }
    public void helper(List<List<Integer>> ans,List<Integer> temp,int start, int[] nums){
        if(start >= nums.length){
            ans.add(new ArrayList<>(temp));
        }
        else{
            temp.add(nums[start]);
            helper(ans,temp,start+1,nums);
            temp.remove(temp.size()-1);
            helper(ans,temp,start+1,nums);
        }
    }
}
