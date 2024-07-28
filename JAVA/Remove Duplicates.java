class Solution {
    String removeDups(String str) {
        Set<Character>  charSet = new  LinkedHashSet<>();
        char[]  strArray = str.toCharArray();
        for(char eachLetter : strArray){
            charSet.add(eachLetter);
        }
        StringBuilder  sb = new StringBuilder();
        for(char ch : charSet){
            sb.append(ch);
        }
        return sb.toString();
    }
}
