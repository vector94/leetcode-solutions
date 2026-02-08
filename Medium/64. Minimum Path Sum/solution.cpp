class Solution {
public:
    
    int minPathSumHelper(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &dp){
        if (i == grid.size() - 1 && j == grid[0].size() - 1)    return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        
        int result = INT_MAX;
        
        if (i + 1 < grid.size()){
            result = min(result, minPathSumHelper(i + 1, j, grid, dp) + grid[i][j]);
        }
        if (j + 1 < grid[0].size()){
            result = min(result, minPathSumHelper(i, j + 1, grid, dp) + grid[i][j]);
        }
        
        return dp[i][j] = result;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m, vector<int> (n, -1));
        
        return minPathSumHelper(0, 0, grid, dp);
    }
};