class Solution {
public:
    
    int helper(int r, int c1, int c2, vector<vector<int> > &grid, vector<vector<vector<int> > > &dp){
        if (r == grid.size())   return 0;
        
        if (c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size())   return -9999;
        
        if (dp[r][c1][c2] != -1)    return dp[r][c1][c2];
        
        int toAdd;
        if (c1 == c2)   toAdd = grid[r][c1];
        else            toAdd = grid[r][c1] + grid[r][c2];
        
        int result = 0;
        
        for (int nc1 = c1 - 1; nc1 <= c1 + 1; nc1++){
            for (int nc2 = c2 - 1; nc2 <= c2 + 1; nc2++){
                result = max(result, helper(r + 1, nc1, nc2, grid, dp) + toAdd);
            }
        }
        
        return dp[r][c1][c2] = result;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<vector<int> > > dp(row, vector<vector<int> > (col, vector<int> (col, -1)));
        
        return max(0, helper(0, 0, grid[0].size() - 1, grid, dp));
    }
};