class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
       int n =nums.length;
       int arr[] =new int[n];
       double maxbit = Math.pow(2,maximumBit) -1;
       int ans =0;
       int temp = n-1;
       for(int i =0;i<n;i++)
       {
        ans =ans^nums[i];
        arr[temp] =ans^(int)maxbit;
        temp--;
       }
       return arr;
    }
}
