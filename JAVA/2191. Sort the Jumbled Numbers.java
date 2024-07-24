class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        int mapwithidx[][] = new int[n][2];
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++)
        {
            int newnum = 0;
            String curr_num = Integer.toString(nums[i]);
            for(int j=0;j<curr_num.length();j++)
            {
                int digit  = curr_num.charAt(j) - '0';
                newnum  = newnum * 10 + mapping[digit];
            }
            mapwithidx[i] = new int[] {newnum , i};
        }
         Arrays.sort(mapwithidx, (a,b)->
                a[0]==b[0] ? a[1] -b[1] : a[0]-b[0]);
        int sortedarray[] = new int[n];
        for(int i=0;i<n;i++)
        {
            sortedarray[i] = nums[mapwithidx[i][1]];
        }    
        return sortedarray;
    }
}
