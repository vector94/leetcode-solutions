class Solution {
public:
    int mark[505][505];
    int island[505*505];

    int solve(int i, int j, int color, vector<vector<int>> &grid){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || mark[i][j] != 0 || grid[i][j] == 0){
            return 0;
        }
        //cout << i << " " << j << " " << color << endl;
        mark[i][j] = color;
        int ret = 1;
        ret += solve(i + 1, j, color, grid);
        ret += solve(i - 1, j, color, grid);
        ret += solve(i, j + 1, color, grid);
        ret += solve(i, j - 1, color, grid);
        return ret;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int color = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 1 && mark[i][j] == 0){
                    //cout << i << " " << j << endl;
                    color++;
                    island[color] = solve(i, j, color, grid);
                }
            }
        }
        int ret = 0;
        bool zero = false;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 0){
                    zero = true;
                    int cur = 1;
                    int u, d, l, r;
                    u = d = l = r = -1;
                    if (j - 1 >= 0 && grid[i][j - 1] == 1){
                        l = mark[i][j - 1];
                        cur += island[l];
                    }
                    if (j + 1 < grid.size() && grid[i][j + 1] == 1 && mark[i][j + 1] != l){
                        r = mark[i][j + 1];
                        cur += island[r];
                    }
                    if (i - 1 >= 0 && grid[i - 1][j] == 1 && mark[i - 1][j] != l && mark[i - 1][j] != r){
                        d = mark[i - 1][j];
                        cur += island[d];
                    }
                    if (i + 1 < grid.size() && grid[i + 1][j] == 1 && mark[i + 1][j] != l && mark[i + 1][j] != r && mark[i + 1][j] != d){
                        u = mark[i + 1][j];
                        cur += island[u];
                    }
                    ret = max(ret, cur);
                }
            }
        }
        if (!zero){
            return (int)grid.size() * (int)grid.size();
        }
        return ret;
    }
};
