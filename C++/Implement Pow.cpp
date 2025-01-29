class Solution {
  public:
    double power(double b, int e) {
        
        int p=abs(e);
        double ans=1;
        while(p){
            if(p%2==0){
                b=b*b;
                p/=2;
            }
            else{
                ans=ans*b;
                p=p-1;
            }
        }
        if(e<0)
        return 1/ans;
        return ans;
    }
};

