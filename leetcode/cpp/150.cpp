class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        deque<string> Q;
        int i;
        for (i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                int a = stoi(Q.back()); Q.pop_back();
                int b = stoi(Q.back()); Q.pop_back();
                Q.push_back(to_string(b + a));
            } else if (tokens[i] == "-") {
                int a = stoi(Q.back()); Q.pop_back();
                int b = stoi(Q.back()); Q.pop_back();
                Q.push_back(to_string(b - a));
            } else if (tokens[i] == "*") {
                int a = stoi(Q.back()); Q.pop_back();
                int b = stoi(Q.back()); Q.pop_back();
                Q.push_back(to_string(b * a));
            } else if (tokens[i] == "/") {
                int a = stoi(Q.back()); Q.pop_back();
                int b = stoi(Q.back()); Q.pop_back();
                Q.push_back(to_string(b / a));
            } else {
                Q.push_back(tokens[i]);
            }
        }
        return Q.empty() ? 0 : stoi(Q.front());
    }
};