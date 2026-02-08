class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, -1);
        int mod = 1e9 + 7;
        return solve(1, delay, forget, n, dp, mod);
    }

    int solve(int day, int delay, int forget, int n, vector<int>& dp, int mod){
        if (day > n)    return 0;
        if (dp[day] != -1){
            return dp[day];
        }

        int curCnt = (day > n - forget) ? 1 : 0;
        for (int i = day + delay; i < day + forget; i++){
            curCnt += solve(i, delay, forget, n, dp, mod);
            curCnt %= mod;
        }

        return dp[day] = curCnt;
    }
};
