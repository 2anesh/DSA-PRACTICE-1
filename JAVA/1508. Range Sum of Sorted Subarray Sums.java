class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        int size=n*(n+1)/2;
        int[] newnums = new int[size];
        int k=0;
        for(int i=0;i<n;i++)
        {
            newnums[k]=nums[i];
            k=k+1; 
            for(int j=i+1;j<n;j++)
            {
                newnums[k]=newnums[k-1]+nums[j];
                k=k+1;
            }
        }
        long sum=0;
        Arrays.sort(newnums);
        long mod= 1000000007L;
        for(int i=left-1;i<right;i++)
        {
            sum=(sum+newnums[i])%mod;
        }
        return (int) sum;        
    }
}
