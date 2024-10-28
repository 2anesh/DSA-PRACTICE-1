class Solution {
    public int longestSquareStreak(int[] nums) {
     Set<Integer> st = new HashSet<>();
     for(int i=0;i<nums.length;i++)
     {
        st.add(nums[i]);
     }
     int count=0;
     for(int i=0;i<nums.length;i++)
     {
        int num = nums[i];
        int ct = 0;
        while(st.contains(num))
        {
            ct++;
            if(num>Integer.MAX_VALUE/num)
            break;
            num *= num;
        }
        count = Math.max(count,ct);
     }   
     if(count<=1)
     return -1;
     return count;
    }
}
