class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums){
            totalSum += num;
        }
        if (totalSum & 1)   return false;
        
        int n = nums.size();
        int need = totalSum / 2;
        
        vector<int> dp(need + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++){
            for (int j = need; j >= nums[i]; j--){
                if (nums[i] <= j){
                    dp[j] |= dp[j - nums[i]];
                }
            }
        }
        return dp[need]; 
    }
};