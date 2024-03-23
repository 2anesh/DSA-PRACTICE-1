class Solution {
    int[] Series(int n) {
        if(n==0){
            int f[]={0};
            return f;
        }
        else if(n==1){
            int f[]={0,1};
            return f;
        }
        int m=(int)(1e9+7);
        int fib[]=new int[n+1];
        fib[0]=0;
        fib[1]=1;
        
        for(int i=2;i<=n;i++){
            fib[i]=(fib[i-1]%m+fib[i-2]%m)%m;
        }
        return fib;
        
    }
}
