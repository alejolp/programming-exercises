class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        if (x == 2)
            return 1;
        int a = 1, b = x;
        while (a < b) {
            int64_t m = a + (b - a) / 2;
            if (m == a)
                return a;
            if (m*m < x) {
                a = m;
            } else if (m*m > x) {
                b = m;
            } else {
                return m;
            }
        }
        return a;
    }
};