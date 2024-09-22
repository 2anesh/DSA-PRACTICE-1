class Solution {
  public:
  int lps(string str){
        int n = str.length();
        int LPS[n];
        LPS[0] = 0;  
        int len = 0;  
        int i = 1;
        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len-1];  
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        int max = LPS[n-1];
        return max;
    }
};
