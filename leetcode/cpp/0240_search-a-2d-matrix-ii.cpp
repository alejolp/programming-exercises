class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;

        // O(n log m)
        for (int rm = 0; rm < matrix.size(); ++rm) {
            // BS on matrix[rm];
            if (binary_search(matrix[rm].begin(), matrix[rm].end(), target))
                return true;
        }

        return false;
    }
};