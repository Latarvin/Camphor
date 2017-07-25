class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
				vector<vector<int>> result;
				if (num.size() == 0)
					return result;

				sort(nums.begin(), nums.end());

				int n_max = target / num[0];
				if (n_max == 0)
					return result;


    }
};
