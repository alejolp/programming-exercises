class xcompare {
    public:
    bool operator ()(const vector<int> &  a, const vector<int> &  b) const {
        return (a[1] - a[0]) < (b[1] - b[0]);
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto N = costs.size() / 2;
        int sum_of_A = 0;
        
        for (const vector<int> & e : costs) {
            sum_of_A += e[0];
        }
        
        nth_element(costs.begin(), costs.begin() + N, costs.end(), xcompare());
        int sum_of_halve = 0;

        for (size_t k = 0; k < N; ++k) {
            vector<int> & e = costs[k];
            sum_of_halve += e[0] - e[1];
        }

        return sum_of_A - sum_of_halve;
    }
};