class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        string result = "";
        if (n < 1 || n > 3999)
          return result;

        int num_set[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string str_set[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int i = 0;
        while (n != 0) {
          if (n >= num_set[i]) {
            result += str_set[i];
            n -= num_set[i];
          }
          else
            i++;
        }

        return result;
    }
};
