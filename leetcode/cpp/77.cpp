class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > R;
        vector<int> v;
        int i, j;
        
        for (i=0; i<k; ++i) {
            v.push_back(i+1);
        }
        
        for (;;) {
            R.push_back(v);
            for (i=k-1; i>=0; --i) {
                v[i]++;
                if (v[i] <= n) {
                    int p = v[i] + 1;
                    for (j = i + 1; j < k && p <= n; ++j, ++p) {
                        v[j] = p;
                    }
                    if (j == k)
                        break;
                }
            }
            if (i < 0) break;
        }
        
        return R;
    }
};