class Solution {
    static int minSteps(int d) {
       int step = 0;
        long sum = 0;
        while (sum < d || (sum - d) % 2 != 0) {
            step++;
            sum += step;
        }
        return step;
    }
}
