class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        for (int i = m + n - 1; i >= 0; i--) {
          if (A[m-1] > B[n-1]) {
            A[i] = A[m-1];
            m--;
          } else {
            A[i] = B[n-1];
            n--;
          }
        }
        return;
    }
};
