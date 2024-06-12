class Solution {
  public:
    int countNumberswith4(int n) {
        int count = 0;
        for (int num = 1; num <= n; num++) {
            if (to_string(num).find('4') != string::npos) {
                count++;
            }
        }
        return count;
    }
};
