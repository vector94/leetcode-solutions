class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int> > dp(size, vector<int> (size, -1));
        return solve(0, -1, nums, dp);
    }

    int solve(int idx, int prevIdx, vector<int> &nums, vector<vector<int>> &dp){
        if (idx == nums.size())
            return 0;
        int &len = dp[idx][prevIdx + 1];
        if (len != -1)
            return len;

        len = solve(idx + 1, prevIdx, nums, dp);
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]){
            len = max(len, 1 + solve(idx + 1, idx, nums, dp));
        }
        return len;
    }
};