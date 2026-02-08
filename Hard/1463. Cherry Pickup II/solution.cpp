class Solution {
    int dp[75][75][75];
public:
    
    int helper(int r, int c1, int c2, vector<vector<int> > &grid){
        if (r == grid.size())   return 0;
        
        if (c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size())   return -9999;
        
        if (dp[r][c1][c2] != -1)    return dp[r][c1][c2];
        
        int toAdd;
        if (c1 == c2)   toAdd = grid[r][c1];
        else            toAdd = grid[r][c1] + grid[r][c2];
        
        return dp[r][c1][c2] = max({helper(r + 1, c1 - 1, c2 - 1, grid), helper(r + 1, c1 - 1, c2, grid), helper(r + 1, c1 - 1, c2 + 1, grid),
                                   helper(r + 1, c1, c2 - 1, grid), helper(r + 1, c1, c2, grid), helper(r + 1, c1, c2 + 1, grid),
                                   helper(r + 1, c1 + 1, c2 - 1, grid), helper(r + 1, c1 + 1, c2, grid), helper(r + 1, c1 + 1, c2 + 1, grid)
                                    }) + toAdd;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp, -1, sizeof(dp));
        
        return max(0, helper(0, 0, grid[0].size() - 1, grid));
    }
};