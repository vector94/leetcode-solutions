class Solution {
public:
    
    int robHelper(int index, vector<int> &nums, vector<int> &dp){
        if (index >= nums.size())   return 0;
        if (dp[index] != -1)    return dp[index];
        
        int result = nums[index] + robHelper(index + 2, nums, dp);
        result = max(result, robHelper(index + 1, nums, dp));
        
        return dp[index] = result;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return robHelper(0, nums, dp);
        
    }
};