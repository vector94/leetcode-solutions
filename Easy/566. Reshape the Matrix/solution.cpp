class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        if (m * n != r * c) return mat;
        
        vector<vector<int>> result(r, vector<int> (c));
        
        int x, y;
        x = y = 0;
        
        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[i].size(); j++){
                
                result[y][x] = mat[i][j];
                x++;
                if (x == c){
                    x = 0;
                    y++;
                }
                
            }
        }
        
        return result;
    }
};