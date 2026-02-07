class Solution {
public:
    int minimumDeletions(string s) {
        int N = s.size();
        vector<vector<int>> dp(2, vector<int>(N, -1));

        return solve(0, 0, s, dp);
    }

    int solve(int flag, int idx, string &s, vector<vector<int>> &dp){
        if (idx == s.size())    return 0;
        if (dp[flag][idx] != -1)    return dp[flag][idx];

        int ret = INT_MAX;
        if (flag == 0){
            if (s[idx] == 'a'){
                ret = min(ret, solve(0, idx + 1, s, dp));
            }
            else{
                ret = min(ret, 1 + solve(0, idx + 1, s, dp));
                ret = min(ret, solve(1, idx + 1, s, dp));
            }
        }
        else{
            if (s[idx] == 'a'){
                ret = min(ret, 1 + solve(1, idx + 1, s, dp));
            }
            else{
                ret = min(ret, solve(1, idx + 1, s, dp));
            }
        }

        return dp[flag][idx] = ret;
    }
};