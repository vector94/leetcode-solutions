class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n, -1);
        return solve(0, n, costs, dp);
    }

    long long solve(int idx, int n, vector<int>& costs, vector<int>& dp){
        if (idx == n){
            return 0;
        }
        if (dp[idx] != -1){
            return dp[idx];
        }

        long long ret = solve(idx + 1, n, costs, dp) + costs[idx] + 1;
        if (idx + 2 <= n){
            ret = min(ret, solve(idx + 2, n, costs, dp) + costs[idx + 1] + 4);
        }
        if (idx + 3 <= n){
            ret = min(ret, solve(idx + 3, n, costs, dp) + costs[idx + 2] + 9);
        }

        return dp[idx] = ret; 
    }
};