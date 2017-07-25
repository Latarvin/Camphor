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

        int i = A.size() + B.size() -1;
        int i1 = A.size() - 1, i2 = B.size() - 1;
        while (i1 >= 0 && i2 >= 0) {
          if (A[i1] < B[i2])
            A[i--] = A[i1--];
          else
            A[i--] = B[i2--];
        }

        while (i1 >= 0)
          A[i--] = A[i1--];


        while (i2 >= 0)
          A[i--] = B[i2--];

        return A;
    }
};
