class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n == 1) {
            return 0;
        } else if (n == 2) {
            return 1;
        }

        int former = 0;
        int temp = 1;
        int i = 3;
        int inter;
        while (i <= n) {
            inter = former + temp;
            former = temp;
            temp = inter;
            i++;
        }
        return temp;

    }
};
