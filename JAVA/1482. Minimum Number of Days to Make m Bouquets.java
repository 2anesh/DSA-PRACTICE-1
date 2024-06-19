class Solution {
    public static boolean isPossible(int[] bloomDay, int mid, int m, int k) {
        int adj = 0, bc = 0;
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= mid) {
                adj++;
                if (adj == k) {
                    bc++;
                    adj = 0;
                    if (bc == m) {
                        return true;
                    }
                }
            } else {
                adj = 0;
            }
        }
        return false;
    }    
    public int minDays(int[] bloomDay, int m, int k) {
        int low = Integer.MAX_VALUE;
        int high = Integer.MIN_VALUE;
        
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] < low) {
                low = bloomDay[i];
            }
            if (bloomDay[i] > high) {
                high = bloomDay[i];
            }
        }
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
}
