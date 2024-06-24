class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(q > (2*n)) return 0;
        if(q<2 || q<=n){
        long long  newElement = q-1;
        return newElement;
        }
        long long num = (2*n)-q+1;
        return num;
    }
};
