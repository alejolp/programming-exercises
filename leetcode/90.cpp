class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        set<vector<int> > R;
        int64_t W = 0, LIM = 1LL << S.size();
        
        sort(S.begin(), S.end());

        while (W < LIM) {
            vector<int> v;
            int i;
            for (i=0; i<S.size(); ++i) {
                if (W & (1<<i)) {
                    v.push_back(S[i]);
                }
            }
            R.insert(v);
            W++;
        }
        return vector<vector<int> >(R.begin(), R.end());
    }
};