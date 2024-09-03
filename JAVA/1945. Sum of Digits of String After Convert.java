class Solution {
    public int getLucky(String s, int k) {
        StringBuffer str = new StringBuffer();
        for(int i=0;i<s.length();++i)
        {
            str.append(s.charAt(i) - 96);
        }
        int sum = 0;
        for(int i=0;i<str.length();++i)
        {
            sum += str.charAt(i) - '0';
        }
        while(k>1)
        {
            int temp = sum;
            sum = 0;
            while(temp>0)
            {
                sum += temp%10;
                temp /= 10;
            }
            k--;
        }
        return sum;
    }
}
