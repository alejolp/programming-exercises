class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int,int> M;
        size_t i;
        for (i = 0; i < num.size(); ++i) {
            M[num[i]] += 1;
            if (M[num[i]] > num.size() / 2)
                return num[i];
        }
        return 0;
    }
};