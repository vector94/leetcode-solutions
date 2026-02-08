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
        int dp[605][105][105];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= l; i++){
            for (int j = 0; j <= m; j++){
                for (int k = 0; k <= n; k++){
                    if (count[i - 1][0] <= j && count[i - 1][1] <=k){
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - count[i - 1][0]][k - count[i - 1][1]] + 1);
                    }
                    else{
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};