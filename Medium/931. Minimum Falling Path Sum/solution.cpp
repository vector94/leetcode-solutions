class Solution {
public:
    
    int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if (row == matrix.size())   return 0;
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int result = matrix[row][col];
        
        int a, b, c;
        a = b = c = INT_MAX;
        a = solve(row + 1, col, matrix, dp);
        if (col - 1 >= 0){
            b = solve(row + 1, col - 1, matrix, dp);
        }
        if (col + 1 < matrix[0].size()){
            c = solve(row + 1, col + 1, matrix, dp);
        }
        result += min({a, b, c});
        return dp[row][col] = result;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int> > dp(m, vector<int> (n, -1));
        
        int result = INT_MAX;
        
        for (int j = 0; j < matrix[0].size(); j++){
            result = min(result, solve(0, j, matrix, dp));
        }
        
        return result;
    }
};