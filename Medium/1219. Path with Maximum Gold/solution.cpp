class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
              
        vector<vector<bool> > visited(m, vector<bool> (n, false));
        
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] != 0){
                    visited[i][j] = true;
                    ans = max(ans, backtrack(i, j, grid, visited));
                    visited[i][j] = false;
                }
            }
        }
        
        return ans;
    }
    
private:
    int backtrack(int i, int j, vector<vector<int> >& grid, vector<vector<bool>>& visited){
        int ans = grid[i][j];
        
        int dy[] = {0, -1, 0, 1};
        int dx[] = {-1, 0, 1, 0};
        
        for (int k = 0; k < 4; k++){
            int ny = i + dy[k];
            int nx = j + dx[k];
            
            if (ny < 0 || ny == grid.size() || nx < 0 || nx == grid[0].size() || visited[ny][nx] || grid[ny][nx] == 0){
                continue;
            }
            visited[ny][nx] = true;
            ans = max(ans, grid[i][j] + backtrack(ny, nx, grid, visited));
            
            //cout << i << " " << j << " " << ans << endl;
            //Print(visited);
            
            visited[ny][nx] = false;
        }
        
        return ans;
    }
    
    void Print(vector<vector<bool> > &grid){
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << "------------------" << endl;
    }
};