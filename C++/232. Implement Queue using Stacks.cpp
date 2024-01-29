class MyQueue {
private:
    stack<int> myStack;
public:
    MyQueue() {        
    }    
    void push(int x) {
        stack<int> tmpStack;        
        while(!myStack.empty()) {
            tmpStack.push(myStack.top());
            myStack.pop();
        }
        myStack.push(x);
        while(!tmpStack.empty()) {
            myStack.push(tmpStack.top());
            tmpStack.pop();
        }
    }    
    int pop() {
        int ret = 0;

        if (!myStack.empty()) {
            ret = myStack.top();
            myStack.pop();
        }        
        return ret;
    }    
    int peek() {
        int ret = 0;
        
        if (!myStack.empty())
            ret = myStack.top();        
        return ret;
    }    
    bool empty() {
        return myStack.empty();
    }
};
