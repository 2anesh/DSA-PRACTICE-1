class Solution {
public:
    int helper(const int& n, int count_A, int paste_A)
    {
        if (count_A == n)
            return 0;
        if (count_A > n)
            return 1000;
        int r1 = 1 + helper(n, count_A + paste_A, paste_A),
            r2 = 2 + helper(n, 2 * count_A, count_A);
        return r1 < r2 ? r1 : r2;
    }
    int minSteps(int n) {
        if (n == 1)
            return 0;
        return 1 + helper(n, 1, 1);
    }
};
