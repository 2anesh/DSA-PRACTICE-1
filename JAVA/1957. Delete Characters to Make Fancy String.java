class Solution {
    public String makeFancyString(String s) 
    {
        if(s.length()==1)
            return s;
        StringBuffer str = new StringBuffer(s.substring(0, 2));
        for (int i = 2; i < s.length(); ++i) 
        {
            char ch1 = s.charAt(i - 2);
            char ch2 = s.charAt(i - 1);
            char ch3 = s.charAt(i);
            if (ch1 == ch2) 
            {
                if (ch2 != ch3)
                    str.append(ch3);
            }
            else
                str.append(ch3);
        }
        return str.toString();
    }
}
