class Solution {
public:
    bool checkValidString(std::string s) {
        int lower = 0, upper = 0;        
        for (char ch : s) {
            if (ch == '(') {
                lower++;
                upper++;
            } else if (ch == ')') {
                lower = std::max(lower - 1, 0); 
                upper--;
            } else { // ch == '*'
                lower = std::max(lower - 1, 0); 
                upper++;
            }
            if (upper < 0)
                return false;
        }
        return lower == 0;
    }
};
