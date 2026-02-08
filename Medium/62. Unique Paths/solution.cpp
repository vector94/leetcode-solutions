class Solution {
public:
    
    int uniquePathsHelper(int i, int j, int m, int n, vector<vector<int> > &dp){
        if (i == m && j == n)   return 1;
        
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        
        int result = 0;
        if (i + 1 <= m) result += uniquePathsHelper(i + 1, j, m, n, dp);
        if (j + 1 <= n) result += uniquePathsHelper(i, j + 1, m, n, dp);
        
        return dp[i][j] = result;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, -1));
        return uniquePathsHelper(1, 1, m, n, dp);
    }
};