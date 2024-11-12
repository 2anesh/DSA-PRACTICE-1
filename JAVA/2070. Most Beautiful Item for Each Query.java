class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> Integer.compare(a[0], b[0]));

        int n = items.length;
        int[] maxBeauty = new int[n];
        maxBeauty[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            maxBeauty[i] = Math.max(maxBeauty[i - 1], items[i][1]);
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int queryPrice = queries[i];
            int idx = binarySearch(items, queryPrice);
            result[i] = (idx == -1) ? 0 : maxBeauty[idx];
        }
        
        return result;
    }
    private int binarySearch(int[][] items, int price) {
        int left = 0, right = items.length - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= price) {
                result = mid; 
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
}
