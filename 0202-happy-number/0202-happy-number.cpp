class Solution {
public:
    unordered_set<int> seen;

    int sumOfSquares(int n) {
        if (n == 0) return 0;
        int d = n % 10;
        return d * d + sumOfSquares(n / 10);
    }

    bool isHappy(int n) {
        if (n == 1) return true;
        if (seen.count(n)) return false;

        seen.insert(n);
        return isHappy(sumOfSquares(n));
    }
};
