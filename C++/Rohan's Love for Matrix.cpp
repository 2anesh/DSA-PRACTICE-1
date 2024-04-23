class Solution {
  public:
    int firstElement(int n) {
        int mod= 1000000007;
        int a=1;
        int b=1;
        int c=0;
        for(int i=2;i<n;i++){
            c= (a+b)%mod;
            a=b%mod;
            b=c%mod;
            
        }
        if(n<=2){
            return 1;
        }
        return c;
    }
};
