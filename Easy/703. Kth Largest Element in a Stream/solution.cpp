class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int> > myQueue;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for (int num : nums){
            myQueue.push(num);
        }
        while (myQueue.size() > k){
            myQueue.pop();
        }
    }
    
    int add(int val) {
        myQueue.push(val);
        if (myQueue.size() > k){
            myQueue.pop();
        }
        return myQueue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */