class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> sFactor(N, vector<int>(N, -1));
        queue<pair<int, int>> myQueue;

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (grid[i][j] == 1){
                    sFactor[i][j] = 0;
                    myQueue.push({i, j});
                }
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!myQueue.empty()){
            pair<int, int> cCell = myQueue.front();
            myQueue.pop();

            int x = cCell.first;
            int y = cCell.second;

            for (int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && sFactor[nx][ny] == -1){
                    sFactor[nx][ny] = sFactor[x][y] + 1;
                    myQueue.push({nx, ny});
                }
            }
        }

        int lo = 0;
        int hi = N;
        int ans;

        while (lo <= hi){
            int mid = (lo + hi) / 2;

            vector<vector<bool>> mark(N, vector<bool>(N, false));
            mark[0][0] = true;
            if (check(0, 0, N, sFactor, mark, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }

    bool check(int x, int y, int N, vector<vector<int>>& sFactor, vector<vector<bool>>& mark, int f){
        if (sFactor[x][y] < f)  return false;
        if (x == N - 1 && y == N - 1)   return true;

        bool ret = false;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !mark[nx][ny]){
                mark[nx][ny] = true;
                ret |= check(nx, ny, N, sFactor, mark, f);
            }
        }

        return ret;
    }
};