class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (!nums.size()) return;
        k = k % nums.size();
        while (k--) {
            auto x = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), x);
        }
    }
};