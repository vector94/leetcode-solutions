class Solution {
public:
    
    int maxCoinsHelper(int left, int right, vector<int> &b, vector<vector<int> > &dp){
        
        if (left > right)   return 0;
        
        if (dp[left][right] != -1)  return dp[left][right];
        
        int result = 0;
        
        for (int i = left; i <= right; i++){
            int cur = b[left - 1] * b[i] * b[right + 1] + maxCoinsHelper(left, i - 1, b, dp) + maxCoinsHelper(i + 1, right, b, dp);
            result = max(result, cur);
        }
        
        return dp[left][right] = result;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> b;
        b.push_back(1);
        for (int i = 0; i < nums.size(); i++){
            b.push_back(nums[i]);
        }
        b.push_back(1);
        
        int n = nums.size();
        vector<vector<int> > dp (n + 1, vector<int> (n + 1, -1));
        
        return maxCoinsHelper(1, n, b, dp);
    }
};