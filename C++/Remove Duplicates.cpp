class Solution {
  public:
    string removeDups(string str) {
        int n = str.size(), len = 0, mask = 0;
        for(int i = 0; i < n; i++) {
            int ch = str[i] - 'a';
            if((mask >> ch) & 1) continue;
            mask |= (1 << ch);
            str[len++] = ch + 'a';
        }
        return str.substr(0, len);
    }
};
