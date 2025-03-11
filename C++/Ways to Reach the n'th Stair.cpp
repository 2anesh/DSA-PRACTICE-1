class Solution {
  public:
    int countWays(int n) {
       if(n == 1 || n == 2)return n;
       int first = 1,second = 2;
       for(int i =3;i<=n;i++){
           int curr = first+second;
           first = second;
           second = curr;
       }
       return second;
    }
};
