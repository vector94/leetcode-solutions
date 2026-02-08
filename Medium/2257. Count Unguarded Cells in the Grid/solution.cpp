class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m , vector<int>(n, 0));

        for (int i = 0; i < guards.size(); i++){
            int r = guards[i][0];
            int c = guards[i][1];

            grid[r][c] = 1;
        }

        for (int i = 0; i < walls.size(); i++){
            int r = walls[i][0];
            int c = walls[i][1];

            grid[r][c] = 2;
        }

        for (int i = 0; i < guards.size(); i++){
            for (int r = guards[i][0] - 1; r >= 0; r--){
                if (grid[r][guards[i][1]] == 1 || grid[r][guards[i][1]] == 2){
                    break;
                }
                grid[r][guards[i][1]] = 3;
            }

            for (int r = guards[i][0] + 1; r < m; r++){
                if (grid[r][guards[i][1]] == 1 || grid[r][guards[i][1]] == 2){
                    break;
                }
                grid[r][guards[i][1]] = 3;
            }

            for (int c = guards[i][1] - 1; c >= 0; c--){
                if (grid[guards[i][0]][c] == 1 || grid[guards[i][0]][c] == 2){
                    break;
                }
                grid[guards[i][0]][c] = 3;
            }

            for (int c = guards[i][1] + 1; c < n; c++){
                if (grid[guards[i][0]][c] == 1 || grid[guards[i][0]][c] == 2){
                    break;
                }
                grid[guards[i][0]][c] = 3;
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0)    ans++;
            }
        }

        return ans;
    }
};

/*
    1 -> guard
    2 -> wall
    3 -> visited
*/