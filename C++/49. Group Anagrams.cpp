class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> group;
        for (std::string& str : strs) {
            std::string sorted_word = str;
            std::sort(sorted_word.begin(), sorted_word.end());
            group[sorted_word].push_back(str);
        }
        vector<vector<string>> final_vector;
        for (const auto&[sorted, vec] : group) {
            final_vector.push_back(vec);
        }
        return final_vector;
    }
};
