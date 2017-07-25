class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        for (int i = 0; i < str.size(); i++) {
          for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j])
              return false;
          }
        }
        return true;
    }
};
