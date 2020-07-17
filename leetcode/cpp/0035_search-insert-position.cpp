class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0) return 0;
        if (target < A[0]) return 0;
        if (target > A[n-1]) return n;
        int a=0, b=n;
        while (a<b) {
            int m = a + (b-a)/2;
            if (target > A[m]) {
                if (a == m) a++;
                else a = m;
            } else if (target < A[m]) {
                if (b == m) b--;
                else b = m;
            } else {
                return m;
            }
        }
        return a;
    }
};