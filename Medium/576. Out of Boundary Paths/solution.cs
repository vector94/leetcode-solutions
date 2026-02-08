public class Solution {
    private const int _mod = 1000000007;
    public int FindPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int[,,] dp = new int[m, n, maxMove + 1];
        InitDP(m, n, maxMove, dp);


        return FindPathsHelper(startRow, startColumn, maxMove, m, n, dp);
    }

    private int FindPathsHelper(int i, int j, int moveCount, int m, int n, int[,,] dp){
        if (i < 0 || i == m || j < 0 || j == n){
            return 1;
        }
        if (moveCount == 0){
            return 0;
        }

        if (dp[i, j, moveCount] != -1){
            return dp[i, j, moveCount];
        }

        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };

        long result = 0;
        for (int k = 0; k < 4; k++){
            result += FindPathsHelper(i + dx[k], j + dy[k], moveCount - 1, m, n, dp);
            result %= _mod;
        }

        dp[i, j, moveCount] = (int) result;
        return (int)result;
    }

    private void InitDP(int m, int n, int maxMove, int[,,] dp){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k <= maxMove; k++){
                    dp[i, j, k] = -1;
                }
            }
        }
    }
}