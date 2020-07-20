class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = 0, b = nums.size() - 1, m, w;
        int idx, flag;
        
        if (nums.size() == 0) {
            return -1;
        }
        
        while (a < b) {
            m = a + (b - a) / 2;

            if (nums[m] > nums[b]) {
                a = m + 1;
            } else {
                b = m;
            }
            
            cout << "1: " << a << " " << b << " " << m << '\n';
        }

        m = a + (b - a) / 2;
        a = 0;
        b = nums.size() - 1;
        flag = 0;
        
        while (a <= b) {
            w = a + (b - a) / 2;
            idx = (w + m) % nums.size();
            
            int v = nums[idx];

            if (target > v) {
                a = w + 1;
            } else if (target < v) {
                b = w;
            } else if (target == v) {
                return idx;
            }
            
            cout << "2: " << a << " " << b << " " << m << '\n';
            
            if (a == b) {
                if (flag) break;
                else flag=1;
            }
        }

        return -1;
    }
};
