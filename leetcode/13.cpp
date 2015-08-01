class Solution {
public:
    int romanToInt(string s) {
        const char* romans_str[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int romans_val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int p = 0, num = 0;
        for (int i = 0; i < 13; ++i) {
            int L = strlen(romans_str[i]);
            while (s.compare(p, L, romans_str[i]) == 0) {
                num += romans_val[i];
                p += L;
            }
        }
        return num;
    }
};