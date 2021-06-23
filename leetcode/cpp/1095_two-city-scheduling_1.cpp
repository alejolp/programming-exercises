class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto N = costs.size() / 2;
        int sum_of_A = 0;
        vector<int> diffs;
        
        diffs.reserve(costs.size());
        
        for (const vector<int> & e : costs) {
            auto x = e[0], y = e[1];
            sum_of_A += x;
            diffs.push_back((x - y));
        }
        
        nth_element(diffs.begin(), diffs.begin() + N, diffs.end(), std::greater<int>());
        auto sum_of_diff_half = accumulate(diffs.begin(), diffs.begin() + N, 0);
        
        return sum_of_A - sum_of_diff_half;
    }
};