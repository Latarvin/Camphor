class Solution {
public:
    /**
     * @param s a string
     * @return it's index
     */
    int firstUniqChar(string& s) {
        // Write your code here
        if (s.size() == 0)
          return -1;

        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
          flag = false;

          for (int j = 0; j < s.size(); j++) {
            if (i != j && s[j] == s[i]) {
              flag = true;
              break;
            }
          }

          if (!flag)
            return i;
        }
        return -1;
    }
};
