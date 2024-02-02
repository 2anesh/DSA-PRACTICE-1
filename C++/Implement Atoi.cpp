class Solution{
  public:
    int atoi(string s) {
        reverse(s.begin(), s.end());
        int res = 0, neg = 0;
        while (s.size())
        {
            if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9')
            {
                res += (s[s.size() - 1] - '0');
                
                s.pop_back();
                if (s.size() == 0)   break;
                else res *= 10;
            }
            else if (s[s.size() - 1] == '-' && s.size() != 1)
            {
                neg = 1;
                s.pop_back();
            }
            else    return -1;
        }
        if (neg == 1)   res *= -1;
        return res;
    }
};
