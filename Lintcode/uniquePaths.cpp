class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m < 1 || n < 1)
          return 0;
        if (m == 1 && n == 1)
          return 1;

        int N = m + n - 2, K = m - 1;
        double result = 1.0;
        for (int i = 1; i <= K; i++) {
          result = result * (N - K + i) / i;
        }
        return int(result);
    }
};
