class Solution {
public:
    int dp[605][105][105];
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, strs, m, n);
    }

    int solve(int idx, int curM, int curN, vector<string>& strs, int m, int n){
        if (idx == strs.size()) return 0;

        if (dp[idx][curM][curN] != -1){
            return dp[idx][curM][curN];
        }

        int ret = solve(idx + 1, curM, curN, strs, m, n);

        int one = 0;
        for (char ch : strs[idx]){
            if (ch == '1')  one++;
        }
        int zero = strs[idx].size() - one;

        if (curM + zero <= m && curN + one <= n){
            ret = max(ret, 1 + solve(idx + 1, curM + zero, curN + one, strs, m, n));
        }

        return dp[idx][curM][curN] = ret;
    }
};