class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        long result = a;
        if (b >= 0) {
          for (int i = 0; i < b; i++)
            result++;
        } else {
          for (int i = 0; i > b; i--)
            result--;
        }
        return result;
    }
};
