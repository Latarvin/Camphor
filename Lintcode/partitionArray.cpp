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

    int arrayPairSum(vector<int>& nums) {
      if (nums.size() == 0)
        return 0;

      int sum;
      mergeSort(nums, 0, nums, size-1);
      for (int i = 0; i < nums.size() / 2; i++) {
        sum += nums[2*i];
      }

      return sum;
    }

    void mergeSort(vector<int>& nums, int low, int high) {
      if (high - low <= 1)
        return;
      int mid = (high + low) / 2;
      mergeSort(nums, low, mid);
      mergeSort(nums, mid+1, high);
      merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
      int i = low, j = mid + 1;
      vector<int> tmp;
      while (i <= mid && j <= high) {
        if (nums[i] < nums[j]) {
          tmp.push_back(nums[i]);
          i++;
        } else {
          tmp.push_back(nums[j]);
          j++;
        }
      }

      while (i <= mid) {
        tmp.push_back(nums[i]);
        i++;
      }

      while (j <= high) {
        tmp.push_back(nums[j]);
        j++;
      }

      for (int k = 0; k < tmp.size(); k++) {
        nums[low+k] = tmp[k];
      }
      
      return;
    }
};
