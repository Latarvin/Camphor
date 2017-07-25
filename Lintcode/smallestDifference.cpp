class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        if (A.size() == 0 || B.size() == 0)
          return -1;

        int min_diff = -1;
        for (int i = 0; i < A.size(); i++) {
          for (int j = 0; j < B.size(); j++) {
            if (abs(A[i] - B[j]) < min_diff || min_diff == -1)
              min_diff = abs(A[i] - B[j]);
          }
        }

        return min_diff;
    }
};
