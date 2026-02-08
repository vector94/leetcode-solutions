class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> myVector;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                myVector.push_back(grid[i][j]);
            }
        }

        sort(myVector.begin(), myVector.end());

        for (int i = 1; i < myVector.size(); i++){
            if ((myVector[i] - myVector[0]) % x != 0){
                return -1;
            }
        }

        int target = myVector[myVector.size() / 2];
        int ans = 0;

        for (int n : myVector){
            ans += (abs(n - target)) / x;
        }

        return ans;
    }
};

