class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        int i, w=0;
        for (;; ++w) {
            char c = strs[0][w];
            for (i=0; i<strs.size(); ++i) {
                if (w == strs[i].size() || strs[i][w] != c) {
                    return strs[0].substr(0, w);
                }
            }
        }
        return "";
    }
};
