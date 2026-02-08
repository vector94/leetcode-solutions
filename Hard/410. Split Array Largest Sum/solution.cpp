class Solution {
public:
    
    int solve(int index, int subarrayCount, vector<int> &prefixSum, vector<vector<int> > &dp){
        if (dp[index][subarrayCount] != -1) return dp[index][subarrayCount];
        int n = prefixSum.size();
        if (subarrayCount == 1){
            return dp[index][subarrayCount] = prefixSum[n - 1] - prefixSum[index - 1];
        }
        
        int ret = INT_MAX;
        
        for (int i = 0; i <= (n - index) - subarrayCount; i++){
            ret = min(ret, max(prefixSum[index + i] - prefixSum[index - 1], 
                       solve(index + i + 1, subarrayCount - 1, prefixSum, dp)));
        }
        
        return dp[index][subarrayCount] = ret;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        prefixSum[0] = 0;
        
        for (int i = 0; i < n; i++){
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        vector<vector<int> > dp(n + 1, vector<int> (m + 1, -1));
        
        return solve(1, m, prefixSum, dp);
    }
};
