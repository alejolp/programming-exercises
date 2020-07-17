class Solution {
public:
    bool isNumber(const char *s) {
        const char* p = s;
        while (*p == ' ') p++;
        string w(p);
        while (w.size() && w[w.size() - 1] == ' ')
            w.pop_back();
        if (w.size() == 0)
            return false;
        int i;
        bool dot_found = false;
        bool exp_found = false;
        bool dig_found = false;
        bool min_found = false;
        for (i=0; i < w.size(); ++i) {
            if (w[i] == '-' || w[i] == '+') {
                if ((i != 0) || min_found) {
                    if (w[i-1] != 'e' && w[i-1] != 'E')
                        return false;
                }
                if (i == w.size() - 1) {
                    return false;
                }
                min_found = true;
            } else if (w[i] == '.') {
                if (dot_found || exp_found || (!dig_found && i == (w.size() - 1))) return false;
                dot_found = true;
            } else if (w[i] == 'e' || w[i] == 'E') {
                if (exp_found || !dig_found || (i == (w.size() - 1)) ) return false;
                exp_found = true;
                min_found = false;
            } else if (w[i] >= '0' && w[i] <= '9') {
                dig_found = true;
            } else {
                return false;
            }
        }
        return true;
    }
};