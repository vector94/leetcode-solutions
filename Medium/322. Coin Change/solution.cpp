class Solution {
public:
    const int inf = 1e4 + 10;
    
    int coinChangeHelper(int index, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if (amount == 0)   return 0;
        if (index == coins.size()){
            return inf;
        }
        
        if (dp[index][amount] != -1){
            return dp[index][amount];
        }
        
        int result = inf;
        
        result = min(result, coinChangeHelper(index + 1, amount, coins, dp));
        
        if (amount >= coins[index]){
            int newAmount = amount - coins[index];
            result = min(result, 1 + coinChangeHelper(index, newAmount, coins, dp));
            result = min(result, 1 + coinChangeHelper(index + 1, newAmount, coins, dp));
        }
        
        return dp[index][amount] = result;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //sort(coins.begin(), coins.end());
        vector<vector<int> > dp(n, vector<int>(amount + 1, -1));
        
        int result = coinChangeHelper(0, amount, coins, dp);
        if (result > amount)    return -1;
        return result;
    }
};