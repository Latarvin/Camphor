class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0)
          return 0;
        else if (nums.size() == 1)
          return nums[0];

        int sum_max = -100, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
          sum += nums[i];
          if (sum > sum_max)
            sum_max = sum;

          if (sum < 0)
            sum = 0;
        }
        return sum_max;
    }
};
