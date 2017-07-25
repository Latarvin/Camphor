class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n == 0)
          return 1;
        else if (n > 0)
          return x * myPow(x, n-1);
        else
          return myPow(x, n+1) / x;
    }
};
