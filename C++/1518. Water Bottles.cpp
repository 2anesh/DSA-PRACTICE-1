class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinkBottles=numBottles;
        while(numBottles>=numExchange){
            int exchangedBottles=numBottles/numExchange;
            int extraEmptyBottles=numBottles%numExchange;
            drinkBottles+=exchangedBottles;
            numBottles=exchangedBottles+extraEmptyBottles;
        }
        return drinkBottles;
    }
};
