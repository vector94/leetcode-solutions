class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int N = moveTime.size();
        int M = moveTime[0].size();
        
        vector<vector<vector<int>>> distance(N, vector<vector<int>>(M, vector<int>(2, INT_MAX)));
        
        priority_queue<pair<int, tuple<int, int, int>>> myQueue;
        
        distance[0][0][0] = 0;
        myQueue.push({0, {0, 0, 0}});
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        while (!myQueue.empty()){
            int time = -myQueue.top().first;
            auto [currentX, currentY, parity] = myQueue.top().second;
            myQueue.pop();
            
            for (int i = 0; i < 4; i++){
                int nx = currentX + dx[i];
                int ny = currentY + dy[i];
                
                if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                    int moveCost = (parity == 0) ? 1 : 2;
                    int nextParity = 1 - parity;
                    
                    int nextTime = max(time, moveTime[nx][ny]) + moveCost;
                    
                    if (distance[nx][ny][nextParity] > nextTime){
                        distance[nx][ny][nextParity] = nextTime;
                        myQueue.push({-nextTime, {nx, ny, nextParity}});
                    }
                }
            }
        }
        
        return min(distance[N-1][M-1][0], distance[N-1][M-1][1]);
    }
};