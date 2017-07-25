class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if (array.size() == 0)
          return -1;

        if (array[0] == target)
            return 0;
        if (array[array.size() - 1] == target)
            return array.size() - 1;

        if (array[0] > target || array[array.size() - 1] < target)
          return -1;

        int left = 0, mid, right = array.size() - 1;
        bool flag = false;

        while (right - left > 1) {
          mid = (left + right) / 2;
          if (target == array[mid]) {
            while (array[mid - 1] == target)
              mid--;
            return mid;
          }
          else if (target < array[mid])
            right = mid;
          else
            left = mid;
        }

        return -1;
    }
};
