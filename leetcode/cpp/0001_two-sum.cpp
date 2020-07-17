class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> R;
        map<int, int> M;
        size_t i;
        for (i = 0; i < numbers.size(); ++i) {
            map<int, int>::iterator it = M.find(target - numbers[i]);
            if (it != M.end()) {
                if ( i < it->second ) {
                    R.push_back(i + 1);
                    R.push_back(it->second + 1);
                } else {
                    R.push_back(it->second + 1);
                    R.push_back(i + 1);
                }
                break;
            }
            M[numbers[i]] = i;
        }
        return R;
    }
};