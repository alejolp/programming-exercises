
class Solution {
public:
    int myAtoi(string& str) {
        int i = 0;
        int sign = 1;

        while (i < str.size() && str[i] == ' ') {
            ++i;
        }

        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            sign = 1;
            i++;
        }

        int64_t result = 0;

        while (i < str.size() && isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            if ((sign * result) > INT_MAX) return INT_MAX;
            if ((sign * result) < INT_MIN) return INT_MIN;
            i++;
        }

        return sign * result;
    }
};
