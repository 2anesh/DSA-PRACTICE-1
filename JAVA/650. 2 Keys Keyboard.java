class Solution {
    public int minSteps(int n) {
       if(n==1)
       return 0;
       if(n==2)
       return 2;
       int[] ans = new int[n+1];
       ans[1]=0;
       ans[2]=2;
       for(int i=3;i<=n;i++)
       {
          ans[i]=i;
          int j = i/2;           
           while(j>=1)
           {
             if(i%j==0)
              ans[i] = Math.min(ans[i], ans[j]+i/j);
            j--;
           }
       } 
       return ans[n];
    }
}
