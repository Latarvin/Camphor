class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        if (heights.size() <= 1)
          return 0;

        int result = -1, tmp_area;
        for (int i = 0; i < heights.size(); i++) {
          for (int j = i+1; j < heights.size(); j++) {
            tmp_area = (j - i) * min(heights[i], heights[j]);
            if (tmp_area > result)
              result = tmp_area;
          }
        }

        return result;
    }
};
