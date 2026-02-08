class FreqStack {
    map<int, int> freq;
    map<int, stack<int> > myStack;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        myStack[freq[val]].push(val);
    }
    
    int pop() {
        int ret = myStack[maxFreq].top();
        myStack[maxFreq].pop();
        if (myStack[maxFreq].empty()){
            maxFreq--;
        }
        freq[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */