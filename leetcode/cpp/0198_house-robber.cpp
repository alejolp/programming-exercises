class Solution {
public:
    int dp(vector<int>& nums, vector<int>& table, int i) {
        if (i >= nums.size()) return 0;
        if (table[i] != -1) return table[i];
        if (i+3 < nums.size())
            return (table[i] = nums[i] + max(dp(nums, table, i+2), dp(nums, table, i+3)));
        if (i+2 < nums.size())
            return (table[i] = nums[i] + dp(nums, table, i+2));
        return (table[i] = nums[i]);
    }

    int rob(vector<int>& nums) {
        vector<int> table;
        table.resize(nums.size(), -1);
        return max(dp(nums, table, 0), dp(nums, table, 1));
    }
};