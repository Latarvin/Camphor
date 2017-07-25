class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        if (nums.size() == 0)
          return 0;

        if (nums.size() == 1)
         return nums[0];

        int sum_odd = 0, sum_even = 0;
        for (int i = 0; i < nums.size(); i++) {
          if (i % 2 == 0)
            sum_even += nums[i];
          else
            sum_odd += nums[i];
        }

        if (nums.size() % 2 != 0)
          sum_even -= min( nums[0], nums[nums.size()-1] );

        return (sum_even > sum_odd) ? sum_even : sum_odd;
    }
};
