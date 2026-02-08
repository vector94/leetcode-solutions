class Solution {
    int dp[50];
    int solve(int i, int n){
        if (i == n){
            return 1;
        }
        int &ret = dp[i];
        if (ret != -1){
            return ret;
        }
        ret = 0;
        if (i + 1 <= n){
            ret += solve(i + 1, n);
        }
        if (i + 2 <= n){
            ret += solve(i + 2, n);
        }
        return ret;
    }
public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        int ret = solve(0, n);
        return ret;
    }
};