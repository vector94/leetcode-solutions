class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        if (prices.empty()){
            return ret;
        }
        int curMin = prices[0];
        for (int i = 1; i < prices.size(); i++){
            int cur = prices[i] - curMin;
            ret = max(ret, cur);
            curMin = min(curMin, prices[i]);
        }
        return ret;
    }
};