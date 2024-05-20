class Solution
{
    public long PowMod(long x, long n, long m)
    {
        long rahee = 1;
        if(n == 0) return 1;
        if(n ==1) return x;
         rahee = PowMod(x,(n/2),m);
         rahee = (rahee  *rahee)%m;
         if(n%2 ==1)
         {
             return (rahee *x)%m;
         }
         return rahee ;
    }
}
