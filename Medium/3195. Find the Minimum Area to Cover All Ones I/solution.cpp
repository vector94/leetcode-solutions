class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int up, down, left, right;
        up = grid.size();
        down = 0;
        left = grid[0].size();
        right = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    up = min(up, i);
                    down = max(down, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }

        return (down - up + 1) * (right - left + 1);
    }
};