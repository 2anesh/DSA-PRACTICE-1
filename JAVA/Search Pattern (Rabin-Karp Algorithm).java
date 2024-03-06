class Solution {
    ArrayList<Integer> search(String pattern, String text) {
        ArrayList<Integer> occurrences = new ArrayList<>();
        int patternLength = pattern.length();
        int textLength = text.length();
        long patternHash = calculateHash(pattern, patternLength);
        long textHash = calculateHash(text, patternLength);
        for (int i = 0; i <= textLength - patternLength; i++) {
            if (patternHash == textHash && text.substring(i, i + patternLength).equals(pattern)) {
                occurrences.add(i + 1); 
            }
            if (i < textLength - patternLength) {
                textHash = recalculateHash(text, textHash, i, patternLength);
            }
        }
        return occurrences; 
    }
    private long calculateHash(String str, int length) {
        long hashValue = 0;
        for (int i = 0; i < length; i++) {
            hashValue += str.charAt(i) * Math.pow(101, i); 
        }
        return hashValue;
    }
    private long recalculateHash(String str, long oldHash, int oldIndex, int length) {
        long newHash = oldHash - str.charAt(oldIndex); 
        newHash /= 101; 
        newHash += str.charAt(oldIndex + length) * Math.pow(101, length - 1); 
        return newHash;
    }
}
