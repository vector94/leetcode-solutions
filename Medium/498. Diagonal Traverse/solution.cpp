class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> values(m + n);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                values[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> result;
        for (int i = 0; i <= m + n - 1; i++){
            if (i % 2 != 0){
                for (int j = 0; j < values[i].size(); j++){
                    result.push_back(values[i][j]);
                }
            }
            else{
                for (int j = values[i].size() - 1; j >= 0; j--){
                    result.push_back(values[i][j]);
                }
            }
        }

        return result;
    }
};