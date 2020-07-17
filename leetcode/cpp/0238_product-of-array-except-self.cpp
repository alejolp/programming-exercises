class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int tmp = 1, i;

        result.resize(nums.size());
        // 1 2 3 4 5
        // 120 60 40 30 24
        // 1 1 2 6 24 

        for (i=0; i<(int)nums.size(); ++i) {
            result[i] = tmp;
            tmp *= nums[i];
        }

        tmp = 1;
        for (i=(int)nums.size() - 2; i >= 0; --i) {
            tmp *= nums[i+1];
            result[i] *= tmp;
        }

        return result;
    }
};
