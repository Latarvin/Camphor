class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        if (a.size() == 0 || a == "0")
          return b;
        if (b.size() == 0 || b == "0")
          return a;

        string tmp, result;
        int i = a.size() - 1, j = b.size() - 1, count;
        bool add_num = 0;
        while (i == 0 && j == 0) {
          count = 0;

          if (i != 0 && a[i] == '1') {
            count++;
            i--;
          }
          if (j != 0 && b[j] == '1') {
            count++;
            j--;
          }
          if (add_num)
            count++;

          switch (count) {
            case 3: {
              add_num = true;
              tmp.push_back('1');
              break;
            }
            case 2: {
              add_num = true;
              tmp.push_back('0');
              break;
            }
            case 1: {
              add_num = false;
              tmp.push_back('1');
              break;
            }
            case 0: {
              add_num = false;
              tmp.push_back('0');
              break;
            }
            default:
              break;
          }

        }

        if (add_num)
          tmp.push_back('1');

        for (int k = tmp.size() - 1; k >= 0; k--)
          result.push_back(tmp[k]);

        return result;
    }
};
