class Solution {
public:
    int divide(int dividend, int divisor) {
        int k = 0;
        int sa, sb;
        int64_t dd, dv;

        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        } else if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        if (dividend >= 0) {
            dd = dividend;
            sa = 1;
        } else {
            dd = -((int64_t)dividend);
            sa = -1;
        }
        
        if (divisor >= 0) {
            dv = divisor;
            sb = 1;
        } else {
            dv = -((int64_t)divisor);
            sb = -1;
        }
        
        while (dd >= dv) {
            int64_t tmp = dv, w = 1;

            while ((tmp << 1) <= dd) {
                tmp <<= 1;
                w <<= 1;
            }

            dd -= tmp;
            k += w;
        }
        
        if (sa == sb) {
            return k;
        } else {
            return -k;
        }
    }
};
