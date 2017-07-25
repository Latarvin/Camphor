class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size() <= 1 )
          return 0;

        int profit = 0;
        for (int i = 0; i < prices.size()-1; i++) {
          if (prices[i+1] > prices[i]) {
            profit += prices[i+1] - prices[i];
          }
        }

        return profit;
    }
};
