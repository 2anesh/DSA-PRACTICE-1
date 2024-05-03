class Solution {
    public int compareVersion(String version1, String version2) {
        int i = 0;
        int j = 0;
        int n1 = version1.length();
        int n2 = version2.length();        
        while (i < n1 || j < n2) {
            StringBuilder a = new StringBuilder();
            StringBuilder b = new StringBuilder();
            while (i < n1 && version1.charAt(i) != '.') {
                a.append(version1.charAt(i));
                i++;
            }
            while (j < n2 && version2.charAt(j) != '.') {
                b.append(version2.charAt(j));
                j++;
            }
            int a1 = a.length() > 0 ? Integer.parseInt(a.toString()) : 0;
            int b1 = b.length() > 0 ? Integer.parseInt(b.toString()) : 0;
            if (a1 < b1) {
                return -1;
            } else if (a1 > b1) {
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
}
