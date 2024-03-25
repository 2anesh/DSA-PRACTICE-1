class Solution {
  public List findDuplicates(int[] nums)
   {
   List res = new ArrayList<>();
   Arrays.sort(nums);
   for(int i=0;i<nums.length-1;i++)
     {
   if(nums[i] == nums[i+1])
     {
   res.add(nums[i]);
    }
   }
  return res;
   }
}
