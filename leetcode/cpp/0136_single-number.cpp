class Solution {
public:
    int singleNumber(int A[], int n) {
        int x = 0, i;
        for (i = 0; i < n; ++i)
            x ^= A[i];
        return x;
    }
};