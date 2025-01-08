class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int ans = 0;
        for (int i = 0; i < words.length - 1; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    ans++;
            }
        }
        return ans;
    }

    private boolean isPrefixAndSuffix(String word, String word1) {
        if (word.length() > word1.length())
            return false;
        for (int k = 0; k < word.length(); k++)  //Check if prefix
            if (word.charAt(k) != word1.charAt(k)) 
                return false;
        
        int lastIdxWord1 = word1.length() - 1;
        for (int i = word.length() - 1; i >= 0; i--) { //Check if suffix
            if(word.charAt(i) != word1.charAt(lastIdxWord1--))
                return false;
        }
        return true;
    }
}
