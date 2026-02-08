class MyStack {
public:
    queue<int> myQueue;
    MyStack() {
        
    }
    
    void push(int x) {
        myQueue.push(x);
        int sz = myQueue.size();
        for (int i = 0; i < sz - 1; i++){
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
    }
    
    int pop() {
        int ret = myQueue.front();
        myQueue.pop();
        return ret;
    }
    
    int top() {
        return myQueue.front();
    }
    
    bool empty() {
        return myQueue.empty();
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