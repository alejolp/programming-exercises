class Solution {
public:
    __attribute__((optimize("unroll-loops")))
    void moveZeroes(vector<int>& nums) {
        size_t p1 = 0, p2 = 0;
        while (p2 < nums.size()) {
            nums[p1] = nums[p2];
            if (nums[p1] != 0) p1++;
            p2++;
        }
        while (p1 < nums.size()) {
            nums[p1] = 0;
            p1++;
        }
    }
};