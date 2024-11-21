class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int i = 0;
        int j = i+1;
        int maxi = 0;
        int profit = 0;
        
        while(i < prices.size() && j < prices.size())
        {
            int buy = prices[i];
            int sell = prices[j];
             
            int diff = (sell - buy);
            if(diff >= maxi)
            {
                maxi = diff;
                j++;
            }
            else
            {
                i = j;
                j++;
                profit += maxi;
                maxi = 0;
            }
        }
        
        if(maxi > 0)
        {
            profit += maxi;
        }
        
        return profit;
    }
};
