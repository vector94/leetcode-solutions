class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int> > result(row, vector<int> (column));
        
        for (int i = 0; i < row * column; i++){
            int index = i + k;
            index %= (row * column);
            result[index / column][index % column] = grid[i / column][i % column];
        }
        
        return result;
    }
};