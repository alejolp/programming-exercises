class Solution {
public:
    void reverseWords(string &s) {
        int origsize = s.size();
        vector<string> v;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') i++;
            int p = i;
            while (i < s.size() && s[i] != ' ') i++;
            v.push_back(s.substr(p, i - p));
        }
        s = "";
        s.reserve(origsize);
        for (i=0; i < v.size(); ++i) {
            if (s.size()) s += " ";
            s += v[v.size() - i - 1];
        }
    }
};