class Solution {
    public boolean isCircularSentence(String sentence) {
        String[] words = sentence.split(" ");
        int n = words.length;
        if (n == 1) {
            String s = words[0]  ;
            return s.charAt(0)==s.charAt(s.length()-1);
        }
        for (int i = 0; i < n; i++) {
            String currentWord = words[i];
            String nextWord = words[(i + 1) % n];

            if (currentWord.charAt(currentWord.length() - 1) != nextWord.charAt(0)) {
                return false;
            }
        }
        return true;
    }
}
