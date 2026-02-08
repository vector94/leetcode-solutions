class Solution {
public:
    
    bool not_valid(int i, int j, vector<vector<int> > &matrix){
        return (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size());
    }
    
    int dfs(int i, int j, vector<vector<int> >&matrix, vector<vector<int> >&dp){
        if (dp[i][j] != 0) return dp[i][j];
        int dir_x[] = {-1, 0, 1, 0};
        int dir_y[] = {0, 1, 0, -1};
        
        int ret = 1;
        
        for (int dir = 0; dir < 4; dir++){
            int x = i + dir_x[dir];
            int y = j + dir_y[dir];
            if (!not_valid(x, y, matrix) && matrix[i][j] < matrix[x][y]){
                ret = max(ret, 1 + dfs(x, y, matrix, dp));
            }
        }
        return dp[i][j] = ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int> > dp(m, vector<int> (n, 0));
        
        int result = 1;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                result = max(result, dfs(i, j, matrix, dp));
            }
        }
        
        return result;
    }
};