class Solution
{
    public static long sumSubstrings(String s)
    {
   	    int n = s.length();
        long mod = 1000000007;
        long result = 0;
        long multiplier = 1;
        for (int i = n - 1; i >= 0; i--) {
            long num = Long.parseLong(s.substring(i, i + 1)); 
            long contribution = (num * (i + 1) * multiplier) % mod; 
            result = (result + contribution) % mod; 
            multiplier = (multiplier * 10 + 1) % mod; 
        }
        return result;
    }
}
