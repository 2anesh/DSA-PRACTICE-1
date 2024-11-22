class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int maxProfit = 0;
        int mbp = prices[0]; 
        for(int i =1;i<prices.size();i++){
            mbp = min(mbp , prices[i]); 
            maxProfit = max(maxProfit,prices[i] - mbp); 
        }
        return maxProfit;
    }
};
