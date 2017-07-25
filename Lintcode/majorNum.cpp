class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int former = -1000, tmp, count;

        for (int i = 0; i < nums.size(); i++) {
          if (nums[i] == former)
            continue;
          tmp = nums[i];
          count = 0;
          for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == tmp) {
              count++;
              if (2*count > nums.size())
                return tmp;
            }
          }
          former = tmp;
        }
    }
};
