class MinStack {
public:
    stack<pair<int, int>> ST;
    void push(int val) {
        if (ST.empty()){
            ST.push({val, val});
        }
        else{
            ST.push({val, min(ST.top().second, val)});
        }
    }
    
    void pop() {
        ST.pop();        
    }
    
    int top() {
        return ST.top().first;
    }
    
    int getMin() {
        return ST.top().second;
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