class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n + 1, 0));

        for (int i = 0; i < queries.size(); i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];

            int r2 = queries[i][2];
            int c2 = queries[i][3];

            for (int j = r1; j <= r2; j++){
                grid[j][c1] += 1;
                grid[j][c2 + 1] -= 1;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 1; j < n; j++){
                grid[i][j] += grid[i][j - 1];
            }

            grid[i].pop_back();
        }

        return grid;
    }
};