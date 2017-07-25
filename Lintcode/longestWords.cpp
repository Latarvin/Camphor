class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> *result;
        if (dictionary.size() == 0)
          return result;

        int max_len = 0;
        for (int i; i < dictionary.size(); i++) {
          if (dictionary[i].size() > max_len) {
            result.clear();
            result.push_back(dictionary[i]);
            max_len = dictionary[i].size();
          } else if (dictionary[i].size() == max_len)
            result.push_back(dictionary[i]);
        }

        return result;
    }
};
