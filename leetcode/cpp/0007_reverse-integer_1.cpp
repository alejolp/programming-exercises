class Solution {
public:
    int reverse(int x) {
        int64_t y = 0;
        bool neg = (x < 0);
        x = abs(x);
        while (x != 0) {
            y = y * 10 + (x % 10);
            x = x / 10;
        }
        if (y > (2147483647) || y < (-2147483647 - 1))
            return 0;
        return neg ? (-y) : (y);
    }
};