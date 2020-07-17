class MinStack {
    deque<int> q;
    deque<int> m;
public:
    void push(int x) {
        q.push_back(x);
        if (m.empty()) {
            m.push_back(x);
        } else if (x <= m.back()) {
            m.push_back(x);
        }
    }

    void pop() {
        if (top() == getMin()) {
            m.pop_back();
        }
        q.pop_back();
    }

    int top() {
        return q.back();
    }

    int getMin() {
        return m.back();
    }
};