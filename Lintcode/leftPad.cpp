class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        if (size <= originalStr.size())
          return originalStr;
        else {
          string result(size - originalStr.size(), padChar);
          result += originalStr;
          return result;
        }
    }
};
