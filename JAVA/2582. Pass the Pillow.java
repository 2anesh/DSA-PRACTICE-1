class Solution {
    public int passThePillow(int n, int time) {
        int k = 1;
        int count = 0;
        boolean forward = true;        
        while (count < time) {
            if (forward) {
                k++;
                if (k == n) {
                    forward = false;
                }
            } else {
                k--;
                if (k == 1) {
                    forward = true;
                }
            }
            count++;
        }
        return k;
    }
}
