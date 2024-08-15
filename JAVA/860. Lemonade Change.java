class Solution {
    int d_5 = 0;
    int d_10 = 0;
    public boolean lemonadeChange(int[] bills) {
        for (int i : bills) {
            if (i == 5) {
                d_5++;
            } else if (!change_available(i)) {
                return false;
            }
        }
        return true;
    }
    boolean change_available(int n) {
        if (n == 20) {
            if (d_5 >= 1 && d_10 >= 1) {
                d_5--;
                d_10--;
                return true;
            } else if (d_5 > 2) {
                d_5 -= 3;
                return true;
            }
            return false;
        }
        if (d_5 >= 1) {
            d_5--;
            d_10++;
            return true;
        }
        return false;
    }
}
