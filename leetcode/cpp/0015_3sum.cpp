class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int p3 = 0; p3 < nums.size(); ++p3) {
            if (p3 > 0 && nums[p3] == nums[p3 - 1]) continue;
            
            int p1 = 0;
            int p2 = nums.size() - 1;
            int target = -nums[p3];
            
            while (p1 < p2) {
                int x = nums[p1] + nums[p2];
                if (x == target && p1 != p3 && p2 != p3 && p1 != p2) {
                    auto nn = vector<int>{nums[p3],nums[p1],nums[p2]};
                    sort(nn.begin(), nn.end());
                    result.insert(nn);
                    p1++;
                    p2--;
                } else if (x > target) {
                    p2--;
                } else {
                    p1++;
                }
            }
        }
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};