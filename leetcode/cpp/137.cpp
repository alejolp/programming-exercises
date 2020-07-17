class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int, int> M;
        int i;
        for (i=0; i<n; ++i) {
            map<int,int>::iterator it = M.find(A[i]);
            if (it == M.end()) {
                M[A[i]] = 1;
            } else {
                it->second += 1;
                if (it->second == 3)
                    M.erase(it);
            }
        }
        return M.begin()->first;
    }
};