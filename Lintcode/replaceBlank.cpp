class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if (length == 0)
          return 0;

        int count = 0, i = 0;
        while (string[i] != '\0') {
          if (string[i] == ' ')
            count++;
          i++;
        }

        if (count == 0)
          return length;

        i = length - 1;
        length += count * 2;
        int j = length;
        string[j--] = '\0';
        while (i != j) {
          if (string[i] != ' ') {
            i--;
            j--;
          } else {
            i--;
            string[j--] = '0';
            string[j--] = '2';
            string[j--] = '%';
          }
        }

        return length;
    }
};
