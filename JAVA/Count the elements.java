class Solution
{
    public static int[] countElements(int a[], int b[], int n, int query[], int q)
    {
        int res[] = new int[q];
        int ind = 0;
        for(int i: query) 
        {
            int ele = a[i], count = 0;
            for(int num: b)
                if(num <= ele)
                    count++;
            res[ind++] = count;
        }
        return res;
    }
}
