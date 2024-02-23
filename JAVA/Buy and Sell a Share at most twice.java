class Solution {
    public static int maxProfit(int n, int[] price) {
        int buy1 = Integer.MIN_VALUE;
        int sell1 = 0;
        int buy2 = Integer.MIN_VALUE;
        int sell2 = 0;
        for(int i = 0; i <n; i++) {
            buy1 = Math.max(buy1, -price[i]); 
            sell1 = Math.max(sell1, buy1 + price[i]); 
            buy2 = Math.max(buy2, sell1 - price[i]);
            sell2 = Math.max(sell2, buy2 + price[i]);
        }
        return sell2;
    }
}
