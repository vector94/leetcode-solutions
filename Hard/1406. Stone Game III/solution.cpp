class Solution {
public:
    
    int helper(int index, vector<int> &stoneValue, vector<bool> &mark, vector<int> &dp){
        if (index == stoneValue.size()) return 0;
        if (mark[index])    return dp[index];
        
        mark[index] = true;
        
        int best = INT_MIN;
        
        int total = 0;
        for (int i = index, cnt = 1; i < stoneValue.size() && cnt <= 3; i++, cnt++){
            total += stoneValue[i];
            best = max(best, total - helper(i + 1, stoneValue, mark, dp));
        }
        
        return dp[index] = best;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<bool> mark(n, false);
        vector<int> dp(n);
        
        if (helper(0, stoneValue, mark, dp) == 0){
            return "Tie";
        }
        else if (helper(0, stoneValue, mark, dp) > 0){
            return "Alice";
        }
        else{
            return "Bob";
        }
    }
};