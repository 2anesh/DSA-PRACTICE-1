class Solution{
    static long ans,d;
    static int mod=(int)(1e9+7);
    static long rec(int n){
        if(n==0) return 0;
        rec(n-1);
        long curr=1;
        for(int i=0;i<n;i++){
            curr=(curr*d)%mod;
            d++;
        }
        ans=(ans+curr)%mod;
        return ans;
    }
    static long sequence(int n){
        ans=0;
        d=1;
        return rec(n);
    }
}
