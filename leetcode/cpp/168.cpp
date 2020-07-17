class Solution {
public:
    string convertToTitle(int n) {
        string s;
        if (n == 1)
            return "A";
        while (n) {
            n--;
            s.push_back('A' + (n % 26));
            n = n / 26;
        }
        for (int i = 0; i < s.size() / 2; ++i) {
            swap(s[i], s[s.size() - i - 1]);
        }
        return s;
    }
};