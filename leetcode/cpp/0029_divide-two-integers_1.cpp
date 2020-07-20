class Solution {
public:
    int divide(int64_t dividend, int64_t divisor) {
        int k = 0;
        int sa, sb;
        
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        } else if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        if (dividend >= 0) {sa = 1;}
        else {
            dividend = -dividend;
            sa = -1;
        }
        
        if (divisor >= 0) {sb = 1;}
        else {
            divisor = -divisor;
            sb = -1;
        }
        
        if (divisor == 1) {
            k = dividend;
        } else {
            while (dividend >= divisor) {
                dividend -= divisor;
                ++k;
            }
        }
        
        if (sa == sb) {
            return k;
        } else {
            return -k;
        }
    }
};
