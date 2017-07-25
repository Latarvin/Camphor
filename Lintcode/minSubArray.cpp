class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int min_tmp = nums[0], min_memory = nums[0];
        for (int i = 1; i < nums.size(); i++) {
          min_tmp = min(nums[i], min_tmp + nums[i]);
          min_memory = min(min_tmp, min_memory);
        }
        return min_memory;
    }
};
