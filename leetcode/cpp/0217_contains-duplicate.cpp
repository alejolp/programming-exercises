class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> S(nums.begin(), nums.end());
        return S.size() != nums.size();
    }
};