class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> myMap;

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid.size(); j++){
                myMap[grid[i][j]]++;
            }
        }

        int n = grid.size();
        int repeated, missing;
        for (int i = 1; i <= n*n; i++){
            if (myMap[i] == 2) repeated = i;
            else if (myMap[i] == 0) missing = i;
        }

        return vector<int> ({repeated, missing});
    }
};