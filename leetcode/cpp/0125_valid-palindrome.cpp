class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        string w;
        w.reserve(s.size());
        int i;
        for (i=0; i<s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                w.push_back(s[i] - 'A' + 'a');
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                w.push_back(s[i]);
            } else if (s[i] >= '0' && s[i] <= '9') {
                w.push_back(s[i]);
            }
        }
        return string(w.rbegin(), w.rend()) == w;
    }
};