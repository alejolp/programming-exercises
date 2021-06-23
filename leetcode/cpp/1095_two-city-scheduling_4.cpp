class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto N = costs.size() / 2;
        int sum_of_A = 0;
        vector<int> diffs;
        
        diffs.reserve(costs.size());
        
        for (const vector<int> & e : costs) {
            sum_of_A += e[0];
            diffs.emplace_back((e[0] - e[1]));
        }
        
        nth_element(diffs.begin(), diffs.begin() + N, diffs.end());
        auto sum_of_diff_half = accumulate(diffs.begin() + N, diffs.end(), 0);
        
        return sum_of_A - sum_of_diff_half;
    }
};