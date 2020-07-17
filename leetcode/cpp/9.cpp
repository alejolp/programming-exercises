class Solution {
public:
    bool isPalindrome(int x) {
        int a = 0, b = x, i;
        if (x < 0) return false;
        while (b) {
            int t = a;
            a = a * 10 + (b % 10);
            if (a < t) return false;
            b /= 10;
        }
        return a == x;
    }
};
