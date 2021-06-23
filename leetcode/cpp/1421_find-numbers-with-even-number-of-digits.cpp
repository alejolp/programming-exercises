class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = 0, m = 0;
        int* p = nums.data();
        auto count = nums.size();
        
        for (int i = 0; i < (count & 0x7ffffffell); i += 2) {
            int e = p[i];
            int f = p[i + 1];
            
            if ((e >= 10 && e <= 99) || (e >= 1000 && e <= 9999) || (e >= 100000))
                n++;
            if ((f >= 10 && f <= 99) || (f >= 1000 && f <= 9999) || (f >= 100000))
                m++;
        }
        
        if (count & 0x1) {
            int e = p[count - 1];
            if ((e >= 10 && e <= 99) || (e >= 1000 && e <= 9999) || (e >= 100000))
                n++;
        }
        
        return n + m;
    }
};