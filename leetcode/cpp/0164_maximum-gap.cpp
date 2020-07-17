class Solution {
public:
    int maximumGap(vector<int> &num) {
        int m = 0;
        size_t i;

        if (num.size() < 2)
            return 0;
        
        sort(num.begin(), num.end());
        
        for (i=0; i<num.size() - 1; ++i) {
            m = max(m, abs(num[i] - num[i+1]));
        }
        
        return m;
    }
};