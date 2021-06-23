class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size() - 1;
        while (p1 < p2) {
            auto x = numbers[p1] + numbers[p2];
            if (x == target) {
                break;
            } else if (x < target) {
                p1 = p1 + 1;
            } else {
                p2 = p2 - 1;
            }
        }
        return vector<int>{p1 + 1, p2 + 1};
    }
};