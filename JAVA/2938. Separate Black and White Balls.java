class Solution {
    public long minimumSteps(String s) {
        long res = 0, zero = 0;
        for(int i=s.length()-1;i>=0;--i)
        {
            if(s.charAt(i)=='1')
                res += zero;
            else
                zero++;
        }
        return res;
    }
}
