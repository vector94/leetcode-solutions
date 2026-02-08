class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int smallest = 1e9;
        priority_queue<long> myQueue;
        
        for (int n : nums){
            if (n & 1){
                myQueue.push(n * 2);
                smallest = min(smallest, n * 2);
            }
            else{
                myQueue.push(n);
                smallest = min(smallest, n);
            }
        }
        
        int result = 1e9;
        while (true){
            int biggest = myQueue.top();
            myQueue.pop();
            result = min(result, biggest - smallest);
            if (biggest & 1){
                break;
            }
            smallest = min(smallest, biggest / 2);
            myQueue.push(biggest / 2);
        }
        
        return result;
    }
};