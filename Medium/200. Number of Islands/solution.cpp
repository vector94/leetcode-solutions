class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j])  return;
        visited[i][j] = true;
        dfs(i - 1, j, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
        dfs(i, j + 1, grid, visited);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool> (n, false));
        //vector<vector<int> > dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        int result = 0;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && !visited[i][j]){
                    dfs(i, j, grid, visited);
                    result++;
                }
            }
        }
        
        return result;
    }
};