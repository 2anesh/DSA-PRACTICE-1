class Solution {
    public boolean checkSubarraySum(int[] nums, int k) 
    {
      int n=nums.length;
      int sum=0;
    Map<Integer,Integer> map=new HashMap<>();
    map.put(0,-1);
    for(int i=0; i<n; i++)
    {
        sum=sum+nums[i];
      if(map.containsKey(sum%k))
      {
        int index=map.get(sum%k);
        if(i-index>=2)
        {
            return true;
        }
      }
      else
      {
        map.put(sum%k,i);
      }
    }
    return false;
    }
}
