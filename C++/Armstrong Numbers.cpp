class Solution {
  public:
    string armstrongNumber(int n) {
        int length= 0;
        int sum = 0;
        int m = n;
        while(m!=0){
          m =m/10 ;
          length++;
        }
        m = n;
        while(m!=0){
            int digit=m%10;
            sum = sum +int(pow(digit,length));
            m=m/10;
        }
        if(sum==n){return "true";}
        return "false";
    }
};
