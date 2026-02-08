class Solution {
public:
    
    int jumpHelper(int index, vector<int> &nums, vector<int> &dp){
        if (index >= nums.size() - 1)   return 0;
        if (dp[index] != -1)        return dp[index];
        
        int result = 1e8;
        for (int j = 1; j <= nums[index]; j++){
            result = min(result, jumpHelper(index + j, nums, dp) + 1);
        }
        return dp[index] = result;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return jumpHelper(0, nums, dp);
    }
};