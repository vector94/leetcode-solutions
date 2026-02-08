class Solution {
public:
    
    int calSubsetSize(int index, vector<int> &nums, vector<int> &dp){
        if (index == nums.size()){
            return 0;
        }
        
        if (dp[index] != -1){
            return dp[index];
        }
        
        int result = 1;
        for (int i = index + 1; i < nums.size(); i++){
            if (nums[i] % nums[index] == 0){
                result = max(result, 1 + calSubsetSize(i, nums, dp));
            }
        }
        
        return dp[index] = result;
    }
    
    void subsetPrint(int index, int length, vector<int> &nums, vector<int> &dp, vector<int> &result){
        result.push_back(nums[index]);

        for (int i = index + 1; i < nums.size(); i++){
            if (dp[i] == length - 1 && nums[i] % nums[index] == 0){
                subsetPrint(i, length - 1, nums, dp, result);
                break;
            }
        }
        return;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), -1);
        
        int subLength = 0;
        
        for (int i = 0; i < nums.size(); i++){
            subLength = max(subLength, calSubsetSize(i, nums, dp));
        }
        
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++){
            if (dp[i] == subLength){
                subsetPrint(i, subLength, nums, dp, result);
                break;
            }
        }
        
        return result;
    }
};