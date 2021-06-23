class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = 0, m = 0;
        
        for (int i = 0; i < (nums.size() & 0x7ffffffell); i += 2) {
            int e = nums[i];
            int f = nums[i + 1];
            
            if ((e >= 10 && e <= 99) || (e >= 1000 && e <= 9999) || (e >= 100000))
                n++;
            if ((f >= 10 && f <= 99) || (f >= 1000 && f <= 9999) || (f >= 100000))
                m++;
        }
        
        if (nums.size() & 0x1) {
            int e = nums[nums.size() - 1];
            if ((e >= 10 && e <= 99) || (e >= 1000 && e <= 9999) || (e >= 100000))
                n++;
        }
        
        return n + m;
    }
};