class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int M = grid.size();
        int N = grid[0].size();

        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty()){
            int d = pq.top().first;
            int ux = pq.top().second.first;
            int uy = pq.top().second.second;

            pq.pop();

            for (int i = 0; i < 4; i++){
                int vx = ux + dx[i];
                int vy = uy + dy[i];

                if (vx >= 0 && vx < M && vy >= 0 && vy < N){
                    if (dist[vx][vy] > d + grid[vx][vy]){
                        dist[vx][vy] = d + grid[vx][vy];
                        pq.push({dist[vx][vy], {vx, vy}});
                    }
                }
            }
        }

        return dist[M - 1][N - 1] < health;
    }
};