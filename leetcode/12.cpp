class Solution {
public:
    string intToRoman(int num) {
        const char* romans_str[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int romans_val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string R;
        for (int i = 0; i < 13; ++i) {
            while (num >= romans_val[i]) {
                R += romans_str[i];
                num -= romans_val[i];
            }
        }
        return R;
    }
};
