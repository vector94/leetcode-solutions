class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if (grid[0][0] == 1)    return -1;
        
        int n = grid.size();
        
        int length = 0;
        queue<pair<int, int> > myQueue;
        
        grid[0][0] = 1;
        myQueue.push({0, 0});
        
        int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
        
        while (!myQueue.empty()){
            length++;
            int curSize = myQueue.size();
            while (curSize--){
                pair<int, int> cur = myQueue.front();
                myQueue.pop();

                if (cur.first == n - 1 && cur.second == n - 1)  return length;

                for (int i = 0; i < 8; i++){
                    int nextX = cur.first + dx[i];
                    int nextY = cur.second + dy[i];

                    if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && grid[nextX][nextY] == 0){
                        grid[nextX][nextY] = 1;
                        myQueue.push({nextX, nextY});
                    }
                }
            }
        }
        
        return -1;
    }
};