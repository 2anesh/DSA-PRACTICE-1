class Solution {
    long max_sum(int a[], int n) {
        long s=0,cs=0;
        long ind;
        for(int i=0;i<n;i++){
            s+=a[i];
            ind=i;
            cs+=ind*a[i];
        }
        long ans=cs;
       int k=n-1;
       long N=n;
       while(k>0){
           cs=cs+s-(N*a[k]);
           ans=Math.max(ans,cs);
           k--;
       }
        return ans;
    }
}
