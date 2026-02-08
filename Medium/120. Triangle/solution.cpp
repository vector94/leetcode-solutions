class Solution {
public:
    
    int minimumTotalHelper(int row, int column, int n, vector<vector<int> > &triangle, vector<vector<int> > &dp){
        if (row == n)   return 0;
        if (dp[row][column] != -1)  return dp[row][column];
        
        dp[row][column] = triangle[row][column] + min(minimumTotalHelper(row + 1, column, n, triangle, dp), 
                                                     minimumTotalHelper(row + 1, column + 1, n, triangle, dp));
        
        return dp[row][column];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int> > dp (n, vector<int> (n, -1));
        
        return minimumTotalHelper(0, 0, n, triangle, dp);
    }
};