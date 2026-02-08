class Solution {
public:
    
    int helper(int index, int m, vector<int> &piles, vector<int> &prefixSum, vector<vector<bool> > &mark, vector<vector<int> > &dp){
        if (index == piles.size())  return 0;
        
        if (mark[index][m])     return dp[index][m];
        mark[index][m] = true;
        
        int best = INT_MIN;
        for (int i = index, x = 1; i < piles.size() && x <= 2 * m; i++, x++){
            int total = prefixSum[i + 1] - prefixSum[index];
            best = max(best, total - helper(index + x, max(x, m), piles, prefixSum, mark, dp));
        }
        
        return dp[index][m] = best;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<int>prefixSum(n + 1, 0);
        
        for (int i = 1; i <= n; i++){
            prefixSum[i] = prefixSum[i - 1] + piles[i - 1];
        }
        
        vector<vector<bool> > mark(n, vector<bool> (n + 1, false));
        vector<vector<int> > dp(n, vector<int> (n + 1));
        
        int delta = helper(0, 1, piles, prefixSum, mark, dp);
        
        // total = myScore + opScore;
        // delta = myScore - opScore;
        // total + delta = myScore * 2;
        // myScore = (total + delta) / 2
        
        int total = accumulate(piles.begin(), piles.end(), 0);
        
        return (total + delta) / 2;
    }
};