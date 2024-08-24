class Solution {
    public String nearestPalindromic(String n) {
        int len = n.length();
        int i;
        if (len % 2 == 0) {
            i = len / 2 - 1;  
        } else {
            i = len / 2; 
        }
        long firsthalf = Long.valueOf(n.substring(0, i + 1));
        List<Long> posibility = new ArrayList<>();
        posibility.add(halftopalindrome(firsthalf, len % 2 == 0));
        posibility.add(halftopalindrome(firsthalf - 1, len % 2 == 0));
        posibility.add(halftopalindrome(firsthalf + 1, len % 2 == 0));
        posibility.add((long) Math.pow(10, len - 1) - 1);
        posibility.add((long) Math.pow(10, len) + 1);        
        long diff = Long.MAX_VALUE;  
        long res = 0; 
        long num = Long.valueOf(n);  
        for (long pos : posibility) {
            if (num == pos) {
                continue;  
            }
            if (Math.abs(pos - num) < diff) {
                diff = Math.abs(pos - num);  
                res = pos;  
            } else if (Math.abs(pos - num) == diff) {
                res = Math.min(res, pos);  
            }
        }
        return "" + res;  
    }
    long halftopalindrome(long firsthalf, boolean even) {
        long res = firsthalf;
        if (!even) {
            firsthalf /= 10;  
        }
        while (firsthalf > 0) {
            res = res * 10 + (firsthalf % 10);  
            firsthalf /= 10;
        }
        return res;  
    }
}
