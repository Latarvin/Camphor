class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        if (s.size() == 0)
          return 0;

        int i_space = 0, i = 0;
        while (s[i] != '\0') {
          if (s[i] == ' ')
            i_space = i + 1;
          i++;
        }

        return i - i_space;
    }
};
