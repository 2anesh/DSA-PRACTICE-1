class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        istringstream iss(A + " " + B); 
        unordered_map<string, int> freq; 
        string word; 
        while (iss >> word) ++freq[word];         
        vector<string> ans; 
        for (auto x : freq) {
            if (x.second == 1) ans.push_back(x.first); 
        }
        return ans; 
    }
};
