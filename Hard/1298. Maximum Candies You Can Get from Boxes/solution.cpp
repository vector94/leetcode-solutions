class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int N = status.size();
        vector<bool> hasBox(N, false);
        vector<bool> visited(N, false);

        queue<int> myQueue;
        for (int i = 0; i < initialBoxes.size(); i++){
            hasBox[initialBoxes[i]] = true;

            if (status[initialBoxes[i]] == 1){
                myQueue.push(initialBoxes[i]);
                visited[initialBoxes[i]] = true;
            }
        }

        int result = 0;

        while (!myQueue.empty()){
            int curBox = myQueue.front();
            myQueue.pop();

            result += candies[curBox];

            for (int key : keys[curBox]){
                status[key] = 1;
                if (hasBox[key] && !visited[key]){
                    myQueue.push(key);
                    visited[key] = true;
                }
            }

            for (int box : containedBoxes[curBox]){
                hasBox[box] = true;

                if (status[box] == 1 && !visited[box]){
                    myQueue.push(box);
                    visited[box] = true;
                }
            }
        }

        return result;

    }
};