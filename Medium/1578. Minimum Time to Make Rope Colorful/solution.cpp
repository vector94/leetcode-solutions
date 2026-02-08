class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int N = colors.size();
        vector<vector<int>> dp(27, vector<int>(N, -1));

        return solve(26, 0, colors, neededTime, dp);
    }

    int solve(int prevColor, int idx, string& colors, vector<int>& neededTime, vector<vector<int>>& dp){
        if (idx == colors.size())   return 0;

        if (dp[prevColor][idx] != -1)   return dp[prevColor][idx];

        int ret = solve(prevColor, idx + 1, colors, neededTime, dp) + neededTime[idx];

        int curColor = colors[idx] - 'a';
        if (prevColor != curColor){
            ret = min(ret, solve(curColor, idx + 1, colors, neededTime, dp));
        }

        return dp[prevColor][idx] = ret;
    }
};