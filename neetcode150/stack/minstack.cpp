class MinStack {
public:
    stack<int> s;
    stack<int> mn;
    MinStack() {
    }

    void push(int val) {
        s.push(val);
        if (mn.empty() || mn.top() >= val)
            mn.push(val);
    }
    
    void pop() {
        if (s.top() == mn.top())
            mn.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
