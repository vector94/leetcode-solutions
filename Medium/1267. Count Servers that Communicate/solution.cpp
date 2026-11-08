class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1 || grid[i][j] == 2){
                    int visited = 0;
                    int new_server = 0;
                    for (int x = 0; x < grid.size(); x++){
                        if (grid[x][j] == 2){
                            visited++;
                        }
                        else if (grid[x][j] == 1){
                            grid[x][j] = 2;
                            new_server++;
                        }
                    }
                    for (int y = 0; y < grid[0].size(); y++){
                        if (y == j) continue;
                        if (grid[i][y] == 2){
                            visited++;
                        }
                        else if (grid[i][y] == 1){
                            grid[i][y] = 2;
                            new_server++;
                        }
                    }

                    if (visited + new_server > 1)    ans += new_server;
                }
            }
        }

        return ans;
    }
};