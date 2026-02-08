class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int r = 0; r < n; r++){
            int i = r;
            int j = 0;

            vector<int> v;
            while (i < n && j < m){
                v.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(v.begin(), v.end(), greater<int>());

            i = r;
            j = 0;
            int k = 0;

            while (i < n && j < m){
                grid[i][j] = v[k];
                k++;
                i++;
                j++;
            }
        }

        for (int c = 1; c < m; c++){
            int i = 0;
            int j = c;

            vector<int> v;
            while (i < n && j < m){
                v.push_back(grid[i][j]);
                i++;
                j++;
            }

            sort(v.begin(), v.end());

            i = 0;
            j = c;
            int k = 0;

            while (i < n && j < m){
                grid[i][j] = v[k];
                i++;
                j++;
                k++;
            }
        }

        return grid;
    }
};