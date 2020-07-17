bool cmp(const string& a, const string& b) {
    return (b+a) < (a+b);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        v.reserve(nums.size());
        size_t tam=0;

        for (auto x : nums) {
            v.push_back(to_string(x));
            tam += v[v.size()-1].size();
        }

        std::sort(v.begin(), v.end(), cmp);

        string res;
        res.reserve(tam);

        int i = 0; 
        while (i < v.size() && v[0] == "0") ++i;

        for (; i<v.size(); ++i)
            res += v[i];

        if (i > 0 && !res.size()) res = "0";
        
        return res;
    }
};