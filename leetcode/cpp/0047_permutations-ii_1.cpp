class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > R;
        sort(num.begin(), num.end());
        do {
            R.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return R;
    }
};