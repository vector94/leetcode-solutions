class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int length = mat.size();
        int width = mat[0].size();
        
        vector<vector<int>> matDiagonalElements(length + width);
        
        for (int i = 0; i < length; i++){
            for (int j = 0; j < width; j++){
                int id = i - j;
                matDiagonalElements[id + width - 1].push_back(mat[i][j]);
            }
        }
        
        for (int i = 0; i < length + width; i++){
            sort(matDiagonalElements[i].begin(), matDiagonalElements[i].end());
            int id = i - width + 1;
            int row, col;
            if (id >= 0){
                row = id, col = 0;
            }
            else{
                col = abs(id), row = 0;
            }
            
            for (int j = 0; j < matDiagonalElements[i].size(); j++){
                mat[row][col] = matDiagonalElements[i][j];
                row++;
                col++;
            }
        }
        return mat;
    }
};