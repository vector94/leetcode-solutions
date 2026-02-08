class Solution {
public:
    
    int canPartitionHelper(int index, int sum, int &totalSum, vector<int> &nums, vector<vector<int> > &dp){
        if (index == nums.size())   return 0;
        if (dp[index][sum] != -1)   return dp[index][sum];
        
        if (sum == totalSum - sum)  return dp[index][sum] = true;
        
        int result = 0;
        if (sum + nums[index] <= (totalSum + 1) / 2){
            result |= canPartitionHelper(index + 1, sum + nums[index], totalSum, nums, dp);
        }
        result |= canPartitionHelper(index + 1, sum, totalSum, nums, dp);
        return dp[index][sum] = result;
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums){
            totalSum += num;
        }
        if (totalSum & 1)   return false;
        
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (totalSum, -1));
        return (bool)canPartitionHelper(0, 0, totalSum, nums, dp);
    }
};