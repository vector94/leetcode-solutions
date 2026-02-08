class Solution {
public:
    
    int helper(int left, int right, vector<int> &piles, vector<vector<bool> > &mark, vector<vector<int> > &dp){
        if (left > right)   return 0;
        if (mark[left][right])  return dp[left][right];
        
        mark[left][right] = true;
        
        if ((right - left) % 2 == 0){
            return dp[left][right] = min(helper(left + 1, right, piles, mark, dp) - piles[left], 
                                         helper(left, right - 1, piles, mark, dp) - piles[right]);
        }
        else{
            return dp[left][right] = max(helper(left + 1, right, piles, mark, dp) + piles[left], 
                             helper(left, right - 1, piles, mark, dp) + piles[right]);
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<bool> > mark(n, vector<bool>(n, false));
        vector<vector<int> > dp(n, vector<int>(n));
        
        return helper(0, n - 1, piles, mark, dp) > 0;
    }
};