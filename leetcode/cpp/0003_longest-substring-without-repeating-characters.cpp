class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a=0, b=0;
        int M = 0;
        set<char> Q;
        while (b < s.size()) {
            if (Q.find(s[b]) == Q.end()) {
                Q.insert(s[b]);
                b++;
                M = max(M, b - a);
            } else {
                Q.erase(s[a]);
                a++;
            }
        }
        return M;
    }
};