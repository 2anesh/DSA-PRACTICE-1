class Solution
{
    public int maxSum(int n) 
    { 
        if(n==0||n==1||n==2||n==3) return n;
       int a=(int)n/2;
       int b=(int)n/3;
       int c=(int)n/4;
       int d=a+b+c;
       a=maxSum(a);
       b=maxSum(b);
       c=maxSum(c);
       return Math.max(a+b+c,Math.max(n,d));
    } 
}
