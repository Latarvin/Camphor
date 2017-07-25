class Solution {
public:
    /**
     * @param num a positive number
     * @return true if it's a palindrome or false
     */
    bool palindromeNumber(int num) {
        // Write your code here
        if (num <= 0)
          return false;

        if (num < 10)
          return true;

        vector<int> num_char;
        if (num > 1) {
          num_char.push_back(num % 10);
          num /= 10;
        }
        for (int i = 0; i < num_char.size() / 2; i++) {
          if (num_char[i] != num_char[num_char.size() - 1 - i])
            return false;
        }
        return true;
    }
};
