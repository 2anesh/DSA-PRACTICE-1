class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        String[] strArr1 = Arrays.stream(arr1).mapToObj(String::valueOf).toArray(String[]::new);
        String[] strArr2 = Arrays.stream(arr2).mapToObj(String::valueOf).toArray(String[]::new);
        Arrays.sort(strArr1);
        Arrays.sort(strArr2);
        int maxLength = 0;
        for (String s1 : strArr1) {
            int length = findLongestCommonPrefix(s1, strArr2);
            maxLength = Math.max(maxLength, length);
        }
        return maxLength;
    }
    private int findLongestCommonPrefix(String s1, String[] sortedArr) {
        int left = 0;
        int right = sortedArr.length - 1;
        int maxLength = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int commonLength = getCommonPrefixLength(s1, sortedArr[mid]);
            maxLength = Math.max(maxLength, commonLength);
            if (sortedArr[mid].compareTo(s1) < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return maxLength;
    }
    private int getCommonPrefixLength(String s1, String s2) {
        int minLength = Math.min(s1.length(), s2.length());
        for (int i = 0; i < minLength; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                return i;
            }
        }
        return minLength;
    }
}
