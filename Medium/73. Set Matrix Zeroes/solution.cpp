class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, columns;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }

        for (int row : rows){
            for (int j = 0; j < matrix[0].size(); j++){
                matrix[row][j] = 0;
            }
        }

        for (int col : columns){
            for (int i = 0; i < matrix.size(); i++){
                matrix[i][col] = 0;
            }
        }
        return;
    }
};