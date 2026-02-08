class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        cout << "here" << endl;
        
        vector<vector<int>> sumMatrix(m + 1, vector<int> (n + 1, 0));
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                sumMatrix[i + 1][j + 1] = sumMatrix[i + 1][j] + sumMatrix[i][j + 1] - sumMatrix[i][j] 
                    + mat[i][j];
            }
        }
        
        vector<vector<int> > result(m, vector<int> (n, 0));
        
        for (int i = 0; i < m; i++){
            
            int up = max(i - k, 0);
            int down = min(i + k, m - 1);
            
            for (int j = 0; j < n; j++){
                int left = max(j - k, 0);
                int right = min(j + k, n - 1);
                
                result[i][j] = sumMatrix[down + 1][right + 1] - sumMatrix[down + 1][left] - 
                    sumMatrix[up][right + 1] + sumMatrix[up][left];
            }
        }
        
        return result;
    }
};
