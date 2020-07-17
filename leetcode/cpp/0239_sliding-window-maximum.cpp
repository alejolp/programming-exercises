class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        if (nums.size() < 1) return result;
        
        result.resize(nums.size() - k + 1);

        for (int i = 0; i < result.size(); ++i) {
            result[i] = *max_element(nums.begin() + i, nums.begin() + i + k);
        }

        return result;
    }
};
