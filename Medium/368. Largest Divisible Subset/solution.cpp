class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int N = nums.size();
        vector<vector<int>> dp(N + 1, vector<int>(N, -1));
        
        //solve(0, 0, nums, dp);

        vector<int> result;
        reconstructSubset(0, 0, nums, dp, result);
        return result;
    }

    int solve(int prevIdx, int curIdx, vector<int>& nums, vector<vector<int>>& dp){
        if (curIdx == nums.size())   return 0;
        if (dp[prevIdx][curIdx] != -1)  return dp[prevIdx][curIdx];

        dp[prevIdx][curIdx] = solve(prevIdx, curIdx + 1, nums, dp);

        if (prevIdx == 0 || nums[curIdx] % nums[prevIdx - 1] == 0){
            dp[prevIdx][curIdx] = max(dp[prevIdx][curIdx], 1 + solve(curIdx + 1, curIdx + 1, nums, dp));
        }

        return dp[prevIdx][curIdx];
    }

    void reconstructSubset(int prevIdx, int curIdx, vector<int>& nums, vector<vector<int>>& dp, vector<int>& result) {
        if (curIdx == nums.size()) return;
        
        int skipValue = solve(prevIdx, curIdx + 1, nums, dp);
        
        int takeValue = 0;
        if (prevIdx == 0 || nums[curIdx] % nums[prevIdx - 1] == 0) {
            takeValue = 1 + solve(curIdx + 1, curIdx + 1, nums, dp);
        }
        
        if (takeValue > skipValue) {
            result.push_back(nums[curIdx]);
            reconstructSubset(curIdx + 1, curIdx + 1, nums, dp, result);
        } else {
            reconstructSubset(prevIdx, curIdx + 1, nums, dp, result);
        }
    }
};