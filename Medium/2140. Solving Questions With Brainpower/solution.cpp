class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int N = questions.size();
        vector<long long> dp(N, -1);

        return solve(0, questions, dp);
    }

    long long solve(int i, vector<vector<int>>& questions, vector<long long>& dp){
        if (i >= questions.size())  return 0;
        if (dp[i] != -1)    return dp[i];

        long long maxPoints = questions[i][0] + solve(i + questions[i][1] + 1, questions, dp);
        maxPoints = max(maxPoints, solve(i + 1, questions, dp));

        return dp[i] = maxPoints;
    }
};