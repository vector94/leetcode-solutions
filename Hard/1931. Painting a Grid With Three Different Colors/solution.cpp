class Solution {
public:
    int MOD = 1e9 + 7;
    vector<string> columnStates;
    vector<vector<int>> dp;

    void generateColumnStates(string curCol, int remRows, char prevChar){
        if (remRows == 0){
            columnStates.push_back(curCol);
            return;
        }

        for (char ch : {'R', 'G', 'B'}){
            if (ch == prevChar){
                continue;
            }

            generateColumnStates(curCol + ch, remRows - 1, ch);
        }
    }

    int colorTheGrid(int m, int n) {
        columnStates.clear();
        generateColumnStates("", m, 'x');

        dp.assign(n, vector<int>(columnStates.size(), -1));

        int result = 0;
        for (int i = 0; i < columnStates.size(); i++){
            result += solve(n - 1, i, m);
            result %= MOD;
        }

        return result;
    }

    int solve(int remCols, int prevColIdx, int m){
        if (remCols == 0){
            return 1;
        }

        if (dp[remCols][prevColIdx] != -1){
            return dp[remCols][prevColIdx];
        }

        int ret = 0;
        string prevColumn = columnStates[prevColIdx];

        for (int nxtColIdx = 0; nxtColIdx < columnStates.size(); nxtColIdx++){
            string nextColumn = columnStates[nxtColIdx];
            bool valid = true;

            for (int r = 0; r < m; r++){
                if (prevColumn[r] == nextColumn[r]){
                    valid = false;
                    break;
                }
            }

            if (valid){
                ret += solve(remCols - 1, nxtColIdx, m);
                ret %= MOD;
            }
        }

        return dp[remCols][prevColIdx] = ret;
    }
};