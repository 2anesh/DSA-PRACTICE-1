class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int empty = 0;        
        while (numBottles + empty >= numExchange) {
            int temp = numBottles + empty;
            numBottles = temp / numExchange;
            empty = temp % numExchange;
            sum += numBottles;
        }        
        return sum;
    }
}
