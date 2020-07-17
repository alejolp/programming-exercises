class Solution {
    double pow2(double x, int64_t n) {
        if (n == 0)
            return 1.0;
        if (n % 2) {
            return x * pow2(x, n - 1);
        } else {
            double tmp = pow2(x, n / 2);
            return tmp * tmp;
        }
    }
public:
    double pow(double x, int n) {
        double r = 1;
        int64_t n2 = n;
        bool neg;
        if (n2 < 0) {
            neg = true;
            n2 = -n2;
        } else {
            neg = false;
        }
        r = pow2(x, n2);
        return neg ? 1.0 / r : r;
    }
};