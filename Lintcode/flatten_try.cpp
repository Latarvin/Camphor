/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> result;

        if (nestedList.size() == 0)
          return result;

        for (int i = 0; i < nestedList.size(); i++) {
          if (nestedList[i].isInteger())
            result.push_back(nestedList[i]);
          else {
            vector<int> tmp = flatten(nestedList[i++].getList());
            for (int j = 0; j < tmp.size(); j++)
              result.push_back(tmp[j]);
          }
        }

        return result;
    }
};
