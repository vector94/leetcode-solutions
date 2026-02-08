class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> myQueue;
        for (int s : stones){
            myQueue.push(s);
        }
        
        while (myQueue.size() >= 2){
            int y = myQueue.top();
            myQueue.pop();
            int x = myQueue.top();
            myQueue.pop();
            
            if (x != y){
                myQueue.push(y - x);
            }
        }
        
        if (myQueue.empty()){
            return 0;
        }
        return myQueue.top();
    }
};