class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        int len = A.size();
        int tmp;
        bool flag;

        for (int i = 0; i < len; i++) {
          flag = true;
          for (int j = 0; j < len-i-1; j++) {
            if (A[j] > A[j+1]) {
              tmp = A[j+1];
              A[j+1] = A[j];
              A[j] = tmp;
              flag = false;
            }
          }
          if (flag)
            break;
        }
        return;
    }
};
