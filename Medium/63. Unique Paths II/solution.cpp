class Solution {
public:
    
    int uniquePathHelper(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &dp){
        int m = grid.size();
        int n = grid[0].size();
        
        
        if (i == m - 1 && j == n - 1 && grid[i][j] != 1)   return 1;
        
        if (i == m || j == n || grid[i][j] == 1)    return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int result = uniquePathHelper(i + 1, j, grid, dp);
        result += uniquePathHelper(i, j + 1, grid, dp);
        
        return dp[i][j] = result;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int> > dp(m, vector<int> (n, -1));
        
        return uniquePathHelper(0, 0, obstacleGrid, dp);
    }
};