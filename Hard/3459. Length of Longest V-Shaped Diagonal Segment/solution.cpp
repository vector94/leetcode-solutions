class Solution {
public:
    int dp[501][501][4][2][3];
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    ans = max(ans, 1 + solve(i - 1, j + 1, 0, 1, 1, grid));
                    ans = max(ans, 1 + solve(i + 1, j + 1, 1, 1, 1, grid));
                    ans = max(ans, 1 + solve(i + 1, j - 1, 2, 1, 1, grid));
                    ans = max(ans, 1 + solve(i - 1, j - 1, 3, 1, 1, grid));
                    cout << i << " " << j << " " << ans << endl;
                }
            }
        }
        
        return ans;
    }

    int solve(int i, int j, int dir, int canTakeTurn, int preElem, vector<vector<int>>& grid){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return 0;
        }

        if (((preElem == 1 || preElem == 0) && grid[i][j] != 2) || (preElem == 2 && grid[i][j] != 0)){
            return 0;
        }

        if (dp[i][j][dir][canTakeTurn][preElem] != -1){
            return dp[i][j][dir][canTakeTurn][preElem];
        }

        int bestLen = 0;

        if (canTakeTurn){
            if (dir == 0){
                bestLen = max(bestLen, 1 + solve(i + 1, j + 1, 1, 0, grid[i][j], grid));
            }
            else if (dir == 1){
                bestLen = max(bestLen, 1 + solve(i + 1, j - 1, 2, 0, grid[i][j], grid));
            }
            else if (dir == 2){
                bestLen = max(bestLen, 1 + solve(i - 1, j - 1, 3, 0, grid[i][j], grid));
            }
            else{
                bestLen = max(bestLen, 1 + solve(i - 1, j + 1, 0, 0, grid[i][j], grid));
            }
        }

        if (dir == 0){
            bestLen = max(bestLen, 1 + solve(i - 1, j + 1, 0, canTakeTurn, grid[i][j], grid));
        }
        else if (dir == 1){
            bestLen = max(bestLen, 1 + solve(i + 1, j + 1, 1, canTakeTurn, grid[i][j], grid));
        }
        else if (dir == 2){
            bestLen = max(bestLen, 1 + solve(i + 1, j - 1, 2, canTakeTurn, grid[i][j], grid));
        }
        else{
            bestLen = max(bestLen, 1 + solve(i - 1, j - 1, 3, canTakeTurn, grid[i][j], grid));
        }

        return dp[i][j][dir][canTakeTurn][preElem] = bestLen;

    }
};
