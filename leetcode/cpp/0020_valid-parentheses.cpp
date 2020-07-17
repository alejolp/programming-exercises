class Solution {
public:
    bool isValid(string s) {
        deque<char> st;
        int i;
        for (i=0; i<s.size(); ++i) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    st.push_back(s[i]);
                    break;
                case ')':
                    if (st.empty() || st.back() != '(') return false;
                    st.pop_back();
                    break;
                case ']':
                    if (st.empty() || st.back() != '[') return false;
                    st.pop_back();
                    break;
                case '}':
                    if (st.empty() || st.back() != '{') return false;
                    st.pop_back();
                    break;
                default:
                    return false;
            }
        }
        return st.size() == 0;
    }
};