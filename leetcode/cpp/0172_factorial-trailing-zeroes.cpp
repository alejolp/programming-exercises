class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;
        if (n == 5) return 1;
        int cant5 = 0;
        while (n) {
            n /= 5;
            cant5 += n;
        }
        return cant5;
    }
};