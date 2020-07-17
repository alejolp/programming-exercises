class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> sieve;
        int i, j;
        
        sieve.resize(n+1, 1);
        sieve[0] = 0;
        sieve[1] = 0;
        
        for (i = 2; i*i < sieve.size(); ++i) {
            if (sieve[i]) {
                for (j=i*i; j<sieve.size(); j += i)
                    sieve[j] = 0;
            }
        }
        
        int count = 0;
        for (i = 2; i < n; ++i) {
            if (sieve[i]) ++count;
        }
        return count;
    }
};
