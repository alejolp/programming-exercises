class Solution {
public:
    int reverse(int x) {
        int neg = x < 0;
        int64_t n = 0;
        if (neg) x = -x;
        while (x > 0) {
            int a = x % 10;
            x = x / 10;
            n = n * 10 + a;
        }
        if (n >= (1LL<<31LL)) return 0;
        return neg ? -n : n;
    }
};
