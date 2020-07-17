class Solution {
public:
    bool isScramble(string s1, string s2) {
        int i;
        if (s1.size() != s1.size()) return false;
        if (s1 == s2) return true;
        auto L = s1.size();
        //sort(s1.begin(), s1.end());
        //sort(s2.begin(), s2.end());
        //if (s1 != s2) return false;
        int T[26]={0};
        for (i=0; i<L; ++i) {
            T[s1[i] - 'a']++;
            T[s2[i] - 'a']--;
        }
        for (i=0; i<26; ++i) {
            if (T[i]) return false;
        }

        // ab cde
        // cde ab

        for (i = 1; i < L; ++i) {
            auto s1a = s1.substr(0, i);
            auto s1b = s1.substr(i, L);
            auto s2a = s2.substr(0, i);
            auto s2b = s2.substr(i, L);

            // (aa bb) (ab ba)
            if (isScramble(s1a, s2a) && isScramble(s1b, s2b) || isScramble(s1a, s2b) && isScramble(s1b, s2a))
                return true;

            auto s2c = s2.substr(0, L - i);
            auto s2d = s2.substr(L - i, L);

            if (isScramble(s1a, s2d) && isScramble(s1b, s2c))
                return true;
        }

        return false;
    }
};