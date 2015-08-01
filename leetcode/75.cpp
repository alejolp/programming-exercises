class Solution {
public:
    void sortColors(int A[], int n) {
        int v[3]={0,0,0};
        int i;
        for (i=0; i<n; ++i) {
            v[A[i]]++;
        }
        i = 0;
        while (v[0]--) A[i++] = 0;
        while (v[1]--) A[i++] = 1;
        while (v[2]--) A[i++] = 2;
    }
};