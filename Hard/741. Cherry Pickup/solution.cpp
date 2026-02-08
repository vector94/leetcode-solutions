class Solution {
    int dp[55][55][55][55];
public:
    
    int helper(int r1, int c1, int r2, int c2, vector<vector<int> > &grid){
        if (r1 == grid.size() - 1 && c1 == grid.size() - 1 && r2 == grid.size() - 1 && c2 == grid.size() - 1){
            return grid[r1][c1];
        }
        
        if (r1 == grid.size() || c1 == grid.size() || r2 == grid.size() || c2 == grid.size() || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return -9999;
        } 
        
        if (dp[r1][c1][r2][c2] != -1)   return dp[r1][c1][r2][c2];
        
        int result;
        int toAdd;
        if (r1 == r2 && c1 == c2){
            toAdd = grid[r1][c1];
        }
        else{
            toAdd = grid[r1][c1] + grid[r2][c2];
        }
        
        result = max({helper(r1 + 1, c1, r2 + 1, c2, grid), helper(r1 + 1, c1, r2, c2 + 1, grid),
                      helper(r1, c1 + 1, r2 + 1, c2, grid), helper(r1, c1 + 1, r2, c2 + 1, grid)}) + toAdd;
        
        return dp[r1][c1][r2][c2] = result;
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        if (grid[0][0] == -1)   return 0;
        
        memset(dp, -1, sizeof(dp));
        
        int result = helper(0, 0, 0, 0, grid);
        
        return max(result, 0);
        
    }
};

/*
[[1,1,1,1,0,0,0],
 [0,0,0,1,0,0,0],
 [0,0,0,1,0,0,1],
 [1,0,0,1,0,0,0],
 [0,0,0,1,0,0,0],
 [0,0,0,1,0,0,0],
 [0,0,0,1,1,1,1]]
 
 */