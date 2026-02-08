class Solution {
public:
    int dp[2][1005][5005];
    
    int maxProfitHelper(int sell, int price, int idx, vector<int> &prices){
        if (idx >= prices.size()){
            return 0;
        }
        
        if (dp[sell][price][idx] != -1) return dp[sell][price][idx];
        
        int result = 0;
        
        if (sell){
            if (prices[idx] > price){
                result = (prices[idx] - price) + maxProfitHelper(0, 0, idx + 2, prices);
            }
            result = max(result, maxProfitHelper(sell, price, idx + 1, prices));   
        }
        
        else{
            result = maxProfitHelper(1, prices[idx], idx + 1, prices);
            result = max(result, maxProfitHelper(0, 0, idx + 1, prices));
        }
        return dp[sell][price][idx] = result;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return maxProfitHelper(0, 0, 0, prices);
    }
};