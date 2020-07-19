
class Solution {
public:
    int longestValidParentheses(string s) {
        size_t k = 0;
        int m = 0;

        while (k < s.size()) {
            int i = k, c = 0, f = -1;
            int l2 = 0, l2i = -1;
            
            while (i < s.size()) {
                if (s[i] == '(') {
                    c++;
                } else if (s[i] == ')') {
                    if (c > 0) {
                        c--;
                    } else {
                        f = i;
                        break;
                    }
                }
                if (c == 0) {
                    l2 = i - k + 1;
                    l2i = i + 1;
                }
                i++;
            }

            m = max(m, l2);

            if (l2 > 0) {
                k = l2i;
            } else if (f != -1) {
                k = f + 1;
            } else {
                k++;
            }
        }
        
        return m;
    }
};
