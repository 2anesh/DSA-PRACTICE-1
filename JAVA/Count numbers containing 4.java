class Solution {
    public static int countNumberswith4(int n) {
        int cnt=0;
        int i=1;
       while(i<=n)
        {
          int num=i;
          while(num>0)
          {
              int r=num%10;
              if(r==4)
              {
                  cnt++;
                  break;
              }
              num=num/10;
          }
          i++;
        }
        return cnt;
    }
}
