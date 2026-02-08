class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int ans = 1e9;

        int left = 0;
        int right = grid[0].size() - 1;
        int up = 0;
        int down = grid.size() - 1;

        for (int i = up; i < down; i++){
            ans = min(ans, getMinArea(left, right, up, i, grid) + getMinSumUtil(left, right, i + 1, down, grid));
            ans = min(ans, getMinSumUtil(left, right, up, i, grid) + getMinArea(left, right, i + 1, down, grid));
        }

        cout << ans << endl;

        for (int j = left; j < right; j++){
            ans = min(ans, getMinArea(left, j, up, down, grid) + getMinSumUtil(j + 1, right, up, down, grid));
            ans = min(ans, getMinSumUtil(left, j, up, down, grid) + getMinArea(j + 1, right, up, down, grid));
        }

        return ans;
    }

    int getMinArea(int left, int right, int up, int down, vector<vector<int>>& grid){
        int l = grid[0].size();
        int r = 0;
        int u = grid.size();
        int d = 0;

        for (int i = up; i <= down; i++){
            for (int j = left; j <= right; j++){
                if (grid[i][j] == 1){
                    l = min(l, j);
                    r = max(r, j);
                    u = min(u, i);
                    d = max(d, i);
                }
            }
        }

        return (r - l + 1) * (d - u + 1);
    }

    int getMinSumUtil(int left, int right, int up, int down, vector<vector<int>>& grid){
        int minArea = 1e9;

        for (int i = up; i <= down - 1; i++){
            minArea = min(minArea, getMinArea(left, right, up, i, grid) + getMinArea(left, right, i + 1, down, grid));
        }

        for (int j = left; j <= right - 1; j++){
            minArea = min(minArea, getMinArea(left, j, up, down, grid) + getMinArea(j + 1, right, up, down, grid));
        }

        return minArea;
    }
};