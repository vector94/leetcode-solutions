class Solution {
public:
    
    int maxProfitHelper(int sell, int idx, vector<int> &prices, vector<vector<int> > &dp, int fee){
        if (idx >= prices.size()){
            return 0;
        }
        
        if (dp[sell][idx] != -1)    return dp[sell][idx];
        
        int result = 0;
        
        if (sell){
            result = (prices[idx] - fee) + maxProfitHelper(0, idx + 1, prices, dp, fee);
            result = max(result, maxProfitHelper(1, idx + 1, prices, dp, fee));   
        }
        
        else{
            result = maxProfitHelper(1, idx + 1, prices, dp, fee) - prices[idx];
            result = max(result, maxProfitHelper(0, idx + 1, prices, dp, fee));
        }
        
        return dp[sell][idx] = result;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int> > dp(2, vector<int> (prices.size(), -1));
        return max(0, maxProfitHelper(0, 0, prices, dp, fee));
    }
};