// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int> x;
    stack<int> minnele;
    MinStack() {
    }
    
    void push(int val) {
        x.push(val);
        if(minnele.empty())
        {
            minnele.push(val);
        }
        else
        {
            int t = minnele.top();
            int mi = min(val, t);
            minnele.push(mi);
        }
    }
    
    void pop() {
        x.pop();
        minnele.pop();
    }
    
    int top() {
        return x.top();
    }
    
    int getMin() {
        return minnele.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
