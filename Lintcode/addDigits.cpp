class Solution {
public:
    /**
     * @param num a non-negative integer
     * @return one digit
     */
    int addDigits(int num) {
        // Write your code here
        int digit, sum, tmp;
        while (num >= 10) {
          sum = 0;
          while (num >= 1) {
            sum += num % 10;
            num /= 10;
          }
          num = sum;
        }

        return num;
    }
};
