class Solution {
    long ExtractNumber(String sentence) {
        Pattern pattern = Pattern.compile("\\b\\d+\\b");
        Matcher matcher = pattern.matcher(sentence);
        long maxNum = -1;
        while (matcher.find()) {
            long num = Long.parseLong(matcher.group());
            if (!String.valueOf(num).contains("9") && num > maxNum) {
                maxNum = num;
            }
        }
        return maxNum;
    }
}
