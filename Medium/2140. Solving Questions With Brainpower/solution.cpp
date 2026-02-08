class Solution {
public:
    
    long long helper(int index, vector<vector<int> > &questions, vector<long long> &dp){
        if (index >= questions.size())  return 0;
        
        if (dp[index] != -1)    return dp[index];
        
        long long result = helper(index + 1, questions, dp);
        result = max(result, questions[index][0] + helper(index + questions[index][1] + 1, questions, dp));
        
        return dp[index] = result;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<long long> dp(n, -1);
        
        return helper(0, questions, dp);
        
    }
};