class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string w(s);
        while (w.size() && w[w.size() - 1] == ' ') {
            w.pop_back();
        }
        size_t p = w.rfind(' ');
        if (p == string::npos)
            return w.size();
        return w.size() - p - 1;
    }
};