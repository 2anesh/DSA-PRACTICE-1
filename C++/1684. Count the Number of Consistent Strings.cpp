class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
    int consistentCount = 0;
    bool allowedChars[26] = {false};
    for (char ch : allowed) {
        allowedChars[ch - 'a'] = true;
    }
    for (const std::string& word : words) {
        bool isConsistent = true;
        for (char ch : word) {
            if (!allowedChars[ch - 'a']) {
                isConsistent = false;
                break;
            }
        }
        if (isConsistent) {
            consistentCount++;
        }
    }
    return consistentCount;
    }
};
