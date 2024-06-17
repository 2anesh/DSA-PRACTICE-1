class Solution {
public:
    bool judgeSquareSum(int c) {
        long a=0;
        long b=sqrt(c);
        while(a<=b){
            long squareSum= a*a + b*b;
            if(squareSum==c){
                return true;
            }
            else if(squareSum<c){
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};
