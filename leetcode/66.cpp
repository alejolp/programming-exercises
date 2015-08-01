class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i, carry=0;
        if (digits.size() == 0) {
            vector<int> R;
            R.push_back(1);
            return R;
        }
        digits[digits.size()-1] += 1;
        for (i=digits.size()-1; i>=0; --i) {
            int tmp = (digits[i] + carry);
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};