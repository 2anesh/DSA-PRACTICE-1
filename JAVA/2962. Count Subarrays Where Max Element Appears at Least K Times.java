class Solution {
    public long countSubarrays(int[] nums, int k) {
        int max=0;
        int count=0;
        long len=0;
        int i=0;
        int j=0;
        for(int n:nums)max=Math.max(n,max);
        while(j<nums.length){
            int n=nums[j];
            if(n==max)count++;
            while(count>=k){
                if(nums[i]==max)count--;
                i++;
            }
            len+=j-i+1;
            j++;
        }
       long total = ((long) nums.length * (nums.length + 1)) / 2;
        return  total-len;
    }
}
