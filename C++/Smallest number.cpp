class Solution {
  public:
    string smallestNumber(int s, int d) {
        if (s > 9 * d) {
            return "-1";
        }
        string ans(d, '0');
        s--;
        for (int i = d - 1; i > 0 && s > 0; i--) {
            if (s >= 9) {
                ans[i] = '9';
                s -= 9;
            } else {
                ans[i] = '0' + s;
                s = 0;
            }
        }
        ans[0] = '1' + s;
        return ans;
    }
};
