class Solution {
    public boolean judgeSquareSum(int c) {
        if(c==0) return true;
        int a=(int)Math.sqrt(c);
        int b=0;
        int s=0;
        while(a!=0){
            b=c-a*a;
            s=(int)Math.sqrt(b);
            if(s*s==b) return true;
            else a--;       
        }
        return false;        
    }
}
