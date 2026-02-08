class Solution {
public:
    
    int robHelper(int robbedFirst, int index, vector<int> &nums, vector<vector<int> > &dp){
        if (index >= nums.size())   return 0;
        
        if (dp[robbedFirst][index] != -1){
            return dp[robbedFirst][index];
        }
        
        int result = 0;
        
        if (index == 0){
            result = nums[index] + robHelper(1, index + 2, nums, dp);
            result = max(result, robHelper(0, index + 1, nums, dp));
        }
        else if (index == nums.size() - 1 && robbedFirst){
            return dp[robbedFirst][index] = 0;
        }
        else{
            result = nums[index] + robHelper(robbedFirst, index + 2, nums, dp);
            result = max(result, robHelper(robbedFirst, index + 1, nums, dp));
        }
        
        return dp[robbedFirst][index] = result;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int> (n, -1));
        
        return robHelper(0, 0, nums, dp);
    }
};