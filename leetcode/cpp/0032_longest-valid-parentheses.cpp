
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        int mm = 0;
        
        //stack.reserve(s.size());
        stack.push_back(-1);
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else if (s[i] == ')') {
                int x = stack.back();
                stack.pop_back();
                if (stack.size() > 0) {
                    int y = stack.back();
                    int l = i - y;
                    mm = max(mm, l);
                } else {
                    stack.push_back(i);
                }
            }
        }
        
        return mm;
    }
};
