class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        int ra = 0, rb = matrix.size();

        while (ra < rb) {
            //int rm = ra + (rb - ra) / 2;
            int rm = ra++;
            // BS on matrix[rm];
            if (binary_search(matrix[rm].begin(), matrix[rm].end(), target))
                return true;
            /*
            if (target < matrix[rm].back())
                rb = rm;
            else
                ra = rm + 1;
                */
        }

        return false;
    }
};