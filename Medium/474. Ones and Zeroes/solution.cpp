class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int count[605][2];
        int l = strs.size();
        for (int i = 0; i < l; i++){
            int z, o;
            z = o = 0;
            for (auto ch : strs[i]){
                if (ch == '1')  o++;
                else    z++;
            }
            count[i][0] = z;
            count[i][1] = o;
        }
        int dp[2][105][105];
        int flag = 1;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < l; i++){
            for (int j = 0; j <= m; j++){
                for (int k = 0; k <= n; k++){
                    if (count[i][0] <= j && count[i][1] <= k){
                        dp[flag][j][k] = max(dp[flag ^ 1][j][k], dp[flag ^ 1][j - count[i][0]][k - count[i][1]] + 1);
                    }
                    else{
                        dp[flag][j][k] = dp[flag ^ 1][j][k];
                    }
                }
            }
            flag ^= 1;
        }
        return dp[flag ^ 1][m][n];
    }
};