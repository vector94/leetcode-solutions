class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int N = moveTime.size();
        int M = moveTime[0].size();
        
        priority_queue<pair<int, pair<int, int>>> myQueue;

        vector<vector<int>> distance(55, vector<int> (55, INT_MAX));

        distance[0][0] = 0;
        myQueue.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!myQueue.empty()){
            int dist = -myQueue.top().first;
            int currentX = myQueue.top().second.first;
            int currentY = myQueue.top().second.second;

            myQueue.pop();

            for (int i = 0; i < 4; i++){
                int nx = currentX + dx[i];
                int ny = currentY + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                    int nextDist = max(dist, moveTime[nx][ny]) + 1;
                    if (distance[nx][ny] > nextDist){
                        distance[nx][ny] = nextDist;
                        myQueue.push({-nextDist, {nx, ny}});
                    }
                }
            }
        }

        return distance[N - 1][M - 1];
    }
};