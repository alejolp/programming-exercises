class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        size_t a = 0, b = num.size(), m1, m2;
        
        while (a < b) {
            m1 = a + (b - a) / 3;
            m2 = a + (2 * (b - a)) / 3;
            if (num[m1] < num[m2]) {
                if (a == m1)
                    a++;
                else
                    a = m1;
            } else {
                if (b == m2)
                    b--;
                else
                    b = m2;
            }
        }
        
        return a;
    }
};