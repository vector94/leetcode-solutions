class Solution {
public:
    
    int helper(int index, int sum, vector<int> &nums, int &target, vector<vector<int> > &dp, int &totalSum){
        if (index == nums.size()){
            return (2 * sum - totalSum == target);
        }
        
        if (dp[index][sum] != -1)   return dp[index][sum];
        
        return dp[index][sum] = helper(index + 1, sum + nums[index], nums, target, dp, totalSum) +
                                helper(index + 1, sum, nums, target, dp, totalSum);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        
        for (int n : nums){
            totalSum += n;
        }
        int size = nums.size();
        
        vector<vector<int> > dp(size, vector<int> (totalSum + 1, -1));
        
        return helper(0, 0, nums, target, dp, totalSum);
    }
};