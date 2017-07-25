class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size() <= 1)
          return 0;

        int max_price = -1, min_price = prices[0], max_idx = -1, min_idx = -1,
          min_tmp, max_tmp = -1;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) {
              min_idx = i;
              min_price = prices[i];
              max_tmp = -1;
            } else if (prices[i] > max_tmp)
              max_tmp = prices[i];

            if (prices[i] >= max_price) {
              max_idx = i;
              max_price = prices[i];
              min_tmp = min_price;
            }
        }

        return max(max_price - min_tmp, max_tmp - min_price);
    }
};
