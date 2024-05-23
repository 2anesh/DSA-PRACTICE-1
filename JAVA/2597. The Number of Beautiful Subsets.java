class Solution {
    ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    public void find(int ind,ArrayList<Integer> temp,int[] nums,int k)
    {
        if(ind==nums.length)
        {
            arr.add(temp);
            return;
        }
        if(temp.indexOf(nums[ind]-k)<0)
        {
            temp.add(nums[ind]);
            find(ind+1,temp,nums,k);
            temp.remove(temp.size()-1);
        }
        find(ind+1,temp,nums,k);
    }
    public int beautifulSubsets(int[] nums, int k) {
        if(nums.length==0 || nums.length==1)
            return nums.length;
        Arrays.sort(nums);
        ArrayList<Integer> temp = new ArrayList<Integer>();
        find(0,temp,nums,k);
        return arr.size()-1;
    }   
}
