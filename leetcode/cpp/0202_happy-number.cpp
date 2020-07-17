class Solution {
public:
    bool isHappy(int n) {
        if (n < 0) return false;
        set<int> S;

        while (n != 1) {
            if (S.count(n)) return false;
            S.insert(n);
            int sum = 0;
            while (n > 0) {
                int d = n % 10;
                sum += d*d;
                n = n / 10;
            }
            n = sum;
        }

        return n == 1;
    }
};