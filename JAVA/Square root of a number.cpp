class Solution {
    long floorSqrt(long n) {
        if(n==1)return 1;
       long ans=0;
       for(long i=1;i<=n/2;i++){
           long x =i*i;
           if(x>n)break;
           else{
               ans=i;
           }
       }
       return ans;
    }
}
