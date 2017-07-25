class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> result(2,int(0));
        if (nums.size() <= 1)
          return result;
        for (int i=0; i<nums.size()-1; i++) {
          for (int j=i+1; j<nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
              result[0] = i+1;
              result[1] = j+1;
              return result;
            }
          }
        }
        return result;
    }
};
