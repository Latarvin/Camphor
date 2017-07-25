class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code
        if (A.size() == 0)
          return 0;
        if (A.size() == 1)
          return A[0];

        int count;
        vector<int> nums;
        bool flag;

        for (int i = 0; i < A.size(); i++) {
          if (nums.size() == 0) {
            nums.push_back(A[i]);
            continue;
          }

          flag = true;
          for (int j = 0; j < nums.size(); j++) {
            if (A[i] == nums[j]) {
              flag = false;
              continue;
            }
          }
          if (flag)
            nums.push_back(A[i]);
        }

        for (int j = 0; j < nums.size(); j++) {
          flag = true;
          count = 0;
          for (int i = 0; i < A.size(); i++) {
            if (nums[j] == A[i]) {
              count ++;
              if (count >= 2) {
                flag = false;
                break;
              }
            }
          }

          if (flag)
            return nums[j];
        }
    }
};
