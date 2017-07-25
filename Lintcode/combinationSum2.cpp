class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
	 	int maxAddNum(vector<int> &num, int target) {
			int min_val = 100000;
			for (int i = 0; i < num.size(); i++) {
				if (num[i] < min_val)
					min_val = num[i];
			}
			return target / min_val;
		}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
				int n_max = maxAddNum(num, target);
				vector<vector<int>> result;
				if (n_max == 0)
					return result;

				// int n = 0;
				// vector<int> tmp, now, part;

				for (int i = 0; i < num.size(); i++) {
					vector<int> now;

					if (num[i] > target)
						continue;
					else if (num[i] == target) {
							now.push_back(num[i]);
							result.push_back(now);
							continue;
					}

					vector<int> tmp, part;
					// now.clear();
					// part.clear();
					now.push_back(num[i]);
					for (int j = i + 1; j < num.size(); j++)
						part.push_back(num[j]);

					tmp = combinationSum2(part, target - num[i]);

					if (tmp.size() == 0)
						continue;


				}

				return result;
    }


};
