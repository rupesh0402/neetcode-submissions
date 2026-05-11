class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 1;

        while(n > 1) {
            int temp = first;
            first = first + second;
            second = temp;
            n--;
        }

        return first;
    }
};
