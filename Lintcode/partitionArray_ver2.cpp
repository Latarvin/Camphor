class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0)
          return;

        int left = 0, right = nums.size()-1, tmp;
        while (left != right) {
          while (nums[left] % 2 != 0) {
            left ++;
            if (right == left)
              return;
          }

          while (num[right] % 2 == 0) {
            right--;
            if (right == left)
              return;
          }

          if (nums[left] % 2 == 0 && nums[right] % 2 != 0) {
            tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
          } else if (nums[left] % 2 != 0 && nums[right] % 2 == 0) {
            if (right - left == 1)
              break;
            left++;
            right--;
          } else if (nums[left] % 2 != 0 && nums[right] % 2 != 0) {
            left++;
          } else if (nums[left] % 2 == 0 && nums[right] % 2 == 0) {
            right--;
          }
        }
        return;
    }
};
