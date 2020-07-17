class Solution {
public:
    int findMin(vector<int> &num) {
        int a, b, m;
        if (num.size() == 1) return num[0];
        if (num.size() == 2) return min(num[0], num[1]);
        a = 0;
        b = num.size() - 1;
        while (a < b) {
            if (num[a] == num[b]) {
                int i, x=num[a];
                for (i=a+1; i<=b; ++i) {
                    x=min(x, num[i]);
                }
                return x;
            } else {
                m = a + (b-a) / 2;
                if (num[m] > num[b]) {
                    if (a == m) a++;
                    else a = m;
                } else {
                    if (b == m) b--;
                    else b = m;
                }
            }
        }
        return min(num[0], num[a]);
    }
};