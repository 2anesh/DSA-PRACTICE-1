class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int additions = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else {
                balance--;
                if (balance < 0) {
                    additions++;
                    balance = 0;
                }
            }
        }
        return additions + balance;
    }
};
