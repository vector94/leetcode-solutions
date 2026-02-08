class Solution {
public:
    int minimumTotalHelper(int row, int col, const vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (row >= triangle.size()) return 0;
        
        if (dp[row][col] != INT_MIN) return dp[row][col];
        
        int result = triangle[row][col] + 
                    min(minimumTotalHelper(row + 1, col, triangle, dp),
                        minimumTotalHelper(row + 1, col + 1, triangle, dp));
        
        return dp[row][col] = result;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].assign(i + 1, INT_MIN);
        }
        
        return minimumTotalHelper(0, 0, triangle, dp);
    }
};