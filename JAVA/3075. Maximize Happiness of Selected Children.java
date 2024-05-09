import java.util.Arrays;
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {        
        int n = happiness.length;
        Arrays.sort(happiness);
        int count = 0;
        long sum = 0;
        for (int i = n - 1; count < k; --i){
            sum += Math.max(happiness[i] - count, 0);
            ++count;
        }
        return sum;
    }
}
