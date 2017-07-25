class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        if (a == b)
          return 0;

        int n = 1, count = 0;

        while (n < a && n < b)
          n *= 2;

        while (a == 0 && b == 0) {
          if ((a > n && b < n) || (a < n && b > n))
            count++;

          if (a > n)
            a -= n;

          if (b > n)
            b -= n;

          n /= 2;
        }

        return count;
    }
};
