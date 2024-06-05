class Solution {
    long findSwapValues(long a[], int n, long b[], int m) {
        long sum1=0;
        long sum2=0;
        for(long i:a){
            sum1+=i;
        }
        for(long i:b){
            sum2+=i;
        }
       Arrays.sort(a);
       Arrays.sort(b);
       for(long i:a){
           long x=sum1-i;
           long y=sum2+i;
           int s=0;int l=m-1;
           while(s<=l){
              int mid=(s+l)>>1;
              long k=b[mid];
              
              if(x+k==y-k){
                  return 1;
              }else if(x+k>y-k){
                  l=mid-1;
              }else{
                  s=mid+1;
              }
           }
       }
        return -1;
    }
}
