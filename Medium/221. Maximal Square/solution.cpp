class Solution {
public:
    
    int matrixSquareHelper(int i, int j, vector<vector<char> > &matrix, vector<vector<int> > &dp){
        if (i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        
        int minSize = matrixSquareHelper(i + 1, j, matrix, dp);
        minSize = min(minSize, matrixSquareHelper(i, j + 1, matrix, dp));
        minSize = min(minSize, matrixSquareHelper(i + 1, j + 1, matrix, dp));
        
        int result;
        if (matrix[i][j] == '0'){
            result = 0;
        }
        else{
            result = minSize + 1;
        }
        return dp[i][j] = result;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int> (n, -1));
        
        matrixSquareHelper(0, 0, matrix, dp);
        
        int size = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                size = max(size, dp[i][j]);
            }
        }
        return size * size;
    }
};