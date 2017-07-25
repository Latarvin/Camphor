/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> result;
        Interval tmp, next;

        if (newInterval == NULL)
          return intervals;
        if (interval.size() == 0) {
          result.push_back(newInterval);
          return result;
        }

        if (intervals.size() == 1)
          // add sth

        for (int i = 0; i < intervals.size() - 1; i++) {
          tmp = intervals[i];
          next = interval[i+1];
          if (tmp->end < newInterval->start)
            continue;

        }
    }
};
