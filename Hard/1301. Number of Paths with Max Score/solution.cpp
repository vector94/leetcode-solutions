class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int N = board.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        int maxSum = getMaxSum(N - 1, N - 1, board, dp, visited);
        
        if (maxSum == -1)   return {0, 0};

        vector<vector<int>> count(N, vector<int>(N, -1));

        int pathCount = getPathCount(N - 1, N - 1, board, dp, count);

        vector<int> result = {maxSum, pathCount};

        return result;
    }

    int getPathCount(int x, int y, vector<string>& board, vector<vector<int>>& dp, vector<vector<int>>& count){
        if (x == 0 && y == 0)   return 1;
        if (count[x][y] != -1)  return count[x][y];

        if (dp[x][y] == -1) return count[x][y] = 0;

        int dx[] = {-1, 0, -1};
        int dy[] = {0, -1, -1};

        long long total = 0;

        for (int i = 0; i < 3; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && board[nx][ny] != 'X' && dp[nx][ny] != -1){
                int val = (board[x][y] == 'S') ? 0 : board[x][y] - '0';
                
                long long MOD = 1e9 + 7;
                if (dp[nx][ny] + val == dp[x][y]){
                    total = (total + getPathCount(nx, ny, board, dp, count)) % MOD;
                }
            }
        }

        return count[x][y] = total;
    }

    int getMaxSum(int x, int y, vector<string>& board, vector<vector<int>>& dp, vector<vector<bool>>& visited){
        if (x == 0 && y == 0){
            return dp[x][y] = 0;
            visited[x][y] = true;  
        }

        if (visited[x][y])  return dp[x][y];
        visited[x][y] = true;

        int dx[] = {-1, 0, -1};
        int dy[] = {0, -1, -1};

        int ret = -1;

        for (int i = 0; i < 3; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && board[nx][ny] != 'X'){
                int cur = getMaxSum(nx, ny, board, dp, visited);
                if (cur != -1)  ret = max(ret, cur);
            }
        }

        if (ret == -1)  return dp[x][y] = -1;
        return dp[x][y] = ret + (board[x][y] == 'S' ? 0 : board[x][y] - '0');
    }
};