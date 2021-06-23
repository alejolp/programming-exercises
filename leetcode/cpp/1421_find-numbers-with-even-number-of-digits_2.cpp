class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = 0;
        
        for (int e : nums) {
            if ((e >= 10 && e <= 99) || (e >= 1000 && e <= 9999) || (e >= 100000))
                n++;
        }
        
        return n;
    }
};