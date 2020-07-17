class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i=0, p=0;
        while (i < n) {
            while (i < n && A[i] == elem) ++i;
            if (i < n) {
                if (i != p)
                    A[p] = A[i];
                p++;
                i++;
            }            
        }
        return p;
    }
};