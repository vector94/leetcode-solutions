class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)   return 0;
        vector<int> dp(size);
        dp[0] = dp[1] = 0;
        for (int i = 2; i < size; i++){
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
                dp[i] = dp[i - 1] + 1;
            }
            else{
                dp[i] = 0;
            }
        }
        int result = 0;
        for (int i = 0; i < size; i++){
            result += dp[i];
        }
        return result;
    }
};