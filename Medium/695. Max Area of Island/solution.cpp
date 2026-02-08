class Solution {
public:
    
    int y[4] = {-1, 1, 0, 0};
    int x[4] = {0, 0, -1, 1};
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        
        int total = 1;
        grid[i][j] = 0;
        
        for (int k = 0; k < 4; k++){
            int nextI = i + y[k];
            int nextJ = j + x[k];
            
            if (nextI >= 0 && nextI < grid.size() && nextJ >= 0 && nextJ < grid[0].size() && grid[nextI][nextJ] == 1){
                total += dfs(nextI, nextJ, grid);
            }
        }
        
        return total;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    
                    int cnt = dfs(i, j, grid);
                    result = max(result, cnt);
                
                }
            }
        }
        
        return result;
    }
};