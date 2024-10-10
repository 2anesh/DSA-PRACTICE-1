class Solution {
    public int maxWidthRamp(int[] nums) {
        int len = nums.length;
        int[] leftmin = new int[len];
        int min = nums[0];
        for(int i=0;i<len;++i)
        {
            if(nums[i]<min)
                min = nums[i];
            leftmin[i] = min;
        }
        int[] rightmax = new int[len];
        int max = nums[len-1];
        for(int i=len-1;i>=0;--i)
        {
            if(nums[i]>max)
                max = nums[i];
            rightmax[i] = max;
        }
        int maxLength = -1;
        int i=0,j=0;
        while(i<=j && i<len && j<len)
        {
            if(leftmin[i]<=rightmax[j])
            {
                maxLength = Math.max(maxLength,j-i);
                j++;
            }
            else
                i++;
        }
        return maxLength;
    }
}
