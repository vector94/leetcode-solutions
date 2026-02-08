class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> myQueue;
        int result = 0;
        for (int i = 1; i < heights.size(); i++){
            if (heights[i] <= heights[i - 1]){
                result++;
            }
            else{
                int need = heights[i] - heights[i - 1];
                if (need <= bricks){
                    bricks -= need;
                    myQueue.push(need);
                    result++;
                }
                else{
                    if (ladders == 0){
                        break;
                    }
                    if (myQueue.empty() || myQueue.top() <= need){
                        ladders--;
                    }
                    else{
                        ladders--;
                        bricks += myQueue.top();
                        myQueue.pop();
                        bricks -= need;
                        myQueue.push(need);
                    }
                    result++;
                }
            }
        }
        return result;
    }
};