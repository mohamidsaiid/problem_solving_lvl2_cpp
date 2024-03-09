// https://leetcode.com/problems/implement-queue-using-stacks/ 
class MyQueue {
private:
    stack<int> mian;
    stack<int> secondry;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        mian.push(x);
    }
    
    int pop() {
        while(!mian.empty())
        {
            secondry.push(mian.top());
            mian.pop();
        }
        int topp = secondry.top();
        secondry.pop();
        while(!secondry.empty())
        {
            mian.push(secondry.top());
            secondry.pop();
        }
        return topp;
    }
    
    int peek() {
        while(!mian.empty())
        {
            secondry.push(mian.top());
            mian.pop();
        }
        int topp = secondry.top();
        while(!secondry.empty())
        {
            mian.push(secondry.top());
            secondry.pop();
        }
        return topp;
    }
    
    bool empty() {
        return mian.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
