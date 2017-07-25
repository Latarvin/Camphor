class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        if (A.size() == 0)
          return B;
        if (B.size() == 0)
          return A;

        vector<int> result;
        int i1 = 0, i2 = 0;
        while (i1 < A.size() && i2 < B.size()) {
          if (A[i1] < B[i2]) {
            result.push_back(A[i1]);
            i1++;
          } else {
            result.push_back(B[i2]);
            i2++;
          }
        }

        while (i1 < A.size()) {
          result.push_back(A[i1]);
          i1++;
        }

        while (i2 < B.size()) {
          result.push_back(B[i2]);
          i2++;
        }

        return result;
    }
};
