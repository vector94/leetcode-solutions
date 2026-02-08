class Solution {
public:
    
    int minCostHelper(int index, int n, vector<int> &cost, vector<int> &dp){
        if (index >= n) return 0;
        
        if (dp[index] != -1)    return dp[index];
        
        dp[index] = cost[index] + min(minCostHelper(index + 1, n, cost, dp), minCostHelper(index + 2, n, cost, dp)); 
        
        return dp[index];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        
        return min(minCostHelper(0, n, cost, dp), minCostHelper(1, n, cost, dp));
    }
};