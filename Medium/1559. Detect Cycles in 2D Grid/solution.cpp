class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> mark(m, vector<bool>(n, false));

        bool result = false;

        for (int i = 0; i < m && !result; i++){
            for (int j = 0; j < n && !result; j++){
                if (!mark[i][j]){
                    dfs(i, j, -1, -1, grid, mark, result);
                }
            }
        }

        return result;
    }

    bool check(int x, int y, char curChar, vector<vector<char>>& grid, vector<vector<bool>>& mark){
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || curChar != grid[x][y]){
            return false;
        }
        return true;
    }

    void dfs(int i, int j, int pi, int pj, vector<vector<char>> &grid, vector<vector<bool>> &mark, bool &result){
        mark[i][j] = true;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni == pi && nj == pj)  continue;

            if (check(ni, nj, grid[i][j], grid, mark)){
                if (mark[ni][nj]){
                    result = true;
                    return;
                }
                dfs(ni, nj, i, j, grid, mark, result);
            }
        }
    }
};