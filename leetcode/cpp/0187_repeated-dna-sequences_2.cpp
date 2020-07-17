class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<int> W;
        set<string> result;
        int32_t mask=(1<<20)-1, dna=0;
        size_t start = 0;

        for (int i=0; i<s.size(); ++i) {
            int c=0;
            switch (s[i]) {
                case 'A': c=0; break;
                case 'C': c=1; break;
                case 'G': c=2; break;
                case 'T': c=3; break;
                default: c=0;
            }
            dna = ((dna << 2) | c) & mask;
            if (i >= 9) {
                if (W.count(dna)) {
                    result.insert(s.substr(start, 10));
                } else {
                    W.insert(dna);
                }
                ++start;
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};
