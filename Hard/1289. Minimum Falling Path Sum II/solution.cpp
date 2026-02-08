class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int columnCount = grid[0].size();
        
        vector<vector<int>> dp(rowCount, vector<int> (columnCount, -1));
        
        int ans = INT_MAX;
        for (int i = 0; i < columnCount; i++){
            ans = min(ans, minFallingPathSumHelper(0, i, grid, dp));
        }
        
        return ans;
    }
    
private:
    int minFallingPathSumHelper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if (i == grid.size() - 1){
            return grid[i][j];
        }
        
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for (int k = 0; k < grid[0].size(); k++){
            if (j == k) continue;
            
            ans = min(ans, grid[i][j] + minFallingPathSumHelper(i + 1, k, grid, dp));
        }
        
        return dp[i][j] = ans;
    }
};