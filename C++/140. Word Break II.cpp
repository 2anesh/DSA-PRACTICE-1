class Solution {
public:
    bool foundMatchedWords(string& s, vector<string>& wordDict, vector<string>& matchedWords){
        bool found = false;
        for(vector<string>::iterator it=wordDict.begin(); it != wordDict.end(); ++it){
            string& word = *it;
            if((s.length()>=word.length())
                && (s.compare(0, word.length(), word) == 0)){
                found = true;
                matchedWords.push_back(word);
            }
        }
        return found;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        vector<string> matchedWords;
        if(s.length() == 0){ return sentences;}
        if(foundMatchedWords(s, wordDict, matchedWords) == false){
            sentences.clear();
            return sentences;
        }
        string sentence;
        int count = 0;
        for(vector<string>::iterator it=matchedWords.begin(); it != matchedWords.end(); ++it){
            string& matchedWord = *it;
            string substr = s;
            substr.erase(0, matchedWord.length());
            if(substr.length() == 0){
                sentences.push_back(matchedWord);
                continue;
            }
            vector<string> result_sentences = wordBreak(substr, wordDict);
            count = result_sentences.size();
            for(int i = 0; i < count; ++i){
                sentences.push_back(matchedWord + " " + result_sentences[i]);
            }               
        }
        return sentences;
    }
};
