// https://leetcode.com/problems/implement-stack-using-queues/description/
class MyStack {
public:
    queue<int> x;
    queue<int> y;
    MyStack() {
        
    }
    
    void push(int x) {
        this->x.push(x);
    }
    
    int pop() {
        while(x.size() != 1)
        {
            y.push(x.front());
            x.pop();
        }
        int res = x.front();
        x.pop();
        while(!y.empty())
        {
            x.push(y.front());
            y.pop();
        }
        return res;
    }
    
    int top() {
        return this->x.back();
    }
    
    bool empty() {
        return this->x.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
