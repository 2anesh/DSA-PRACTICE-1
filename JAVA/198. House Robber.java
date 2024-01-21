class Solution {
    public int rob(int[] count) {
        if(count == null|| count.length==0)
        return 0;
        int i;
        for(i=1;i<count.length;i++)
        {
            if(i==1)
            {
                count[i]=Math.max(count[0],count[1]);
            }
            else
            {
                count[i]=Math.max(count[i-1],count[i]+count[i-2]);
            }
        }
        return count[count.length-1];
    }
}
