class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i=0, p=0;
        while (i < n) {
            int x = A[i];
            if (i != p)
                A[p] = A[i];
            p++;
            while (i < n && A[i] == x) ++i;
        }
        return p;
    }
};