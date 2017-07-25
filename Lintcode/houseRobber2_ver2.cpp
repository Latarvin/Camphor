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
        if (nums.size() == 2)
          return max(nums[0], nums[1]);
        if (nums.size() == 3)
          return max(max(nums[0], nums[1]), nums[2]);

        int sum1, sum2, last;
        last = nums[nums.size()-1];
        nums.pop_back();
        sum1 = houseRobber2(nums);
        nums.pop_back();
        sum2 = houseRobber2(nums);

        return max(sum1,sum2+last);
    }
};
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
        if (nums.size() == 2)
          return max(nums[0], nums[1]);
        if (nums.size() == 3)
          return max(max(nums[0], nums[1]), nums[2]);

        int sum1, sum2, last;
        last = nums[nums.size()-1];
        nums.pop_back();
        sum1 = houseRobber2(nums);
        nums.pop_back();
        sum2 = houseRobber2(nums);

        return max(sum1,sum2+last);
    }
};
