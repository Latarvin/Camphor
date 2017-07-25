class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source.size() == 0 || source.size() < target.size())
          return -1;

        int result = 0;
        for (int i = 0; i < source.size(); i++) {
          if (source[i] == target[0]) {
            result = i;
            int ii = i;
            for (int j = 0; j < target.size(); j++) {
              bool flag = true;
              if (source[ii] == target[j]) {
                ii++;
                j++;
              } else {
                flag = false;
                break;
              }
            }

            if (flag)
              return result;
          }
        }
        
        return -1;
    }
};
