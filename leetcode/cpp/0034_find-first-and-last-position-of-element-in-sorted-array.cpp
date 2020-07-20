int xlower_bound(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, med;
    while (start < end) {
        med = (end + start) / 2;

        if (target > nums[med]) {
            start = med + 1;
        } else {
            end = med;
        }
    }
    return start;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int p1 = xlower_bound(nums, target);
        if (nums[p1] != target) return {-1, -1};
        int p2 = xlower_bound(nums, target + 1);
        if ((p2 > 0) && (p2 < nums.size()) && (nums[p2] != target)) {
            p2--;
            if (nums[p2] != target) return {-1, -1};
        }
        //cout << "p1: " << p1 << " p2: " << p2 << "\n";
        return {p1, p2};
    }
};