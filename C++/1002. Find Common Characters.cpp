class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::vector<int> minFreq(26, INT_MAX);
        for (const std::string& word : words) {
            std::vector<int> charCount(26, 0);
            for (char ch : word) {
                charCount[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = std::min(minFreq[i], charCount[i]);
            }
        }
        std::vector<std::string> result;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minFreq[i]; ++j) {
                result.push_back(std::string(1, 'a' + i));
            }
        }
        return result;
    }
};
