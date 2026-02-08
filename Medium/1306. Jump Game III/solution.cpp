class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        bool visited[n];
        memset(visited, false, sizeof(visited));
        
        queue<int> myQueue;
        myQueue.push(start);
        visited[start] = true;
        
        while (!myQueue.empty()){
            int cur = myQueue.front();
            myQueue.pop();
            if (arr[cur] == 0){
                return true;
            }
            
            int nextLeft = cur - arr[cur];
            int nextRight = cur + arr[cur];
            
            if (nextLeft >= 0 && !visited[nextLeft]){
                myQueue.push(nextLeft);
                visited[nextLeft] = true;
            }
            if (nextRight < n && !visited[nextRight]){
                myQueue.push(nextRight);
                visited[nextRight] = true;
            }
        }
        
        return false;
    }
};