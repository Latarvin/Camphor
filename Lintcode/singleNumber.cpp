class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
				bool flag = true;
				for (int i = 0; i < A.size(); i++) {
					flag = true;
					for (int j = i + 1; j < A.size(); j++) {
						if (A[j] == A[i]) {
							flag = false;
							break;
						}
					}
					if (flag)
						return A[i];
				}
				return -1;
    }
};
