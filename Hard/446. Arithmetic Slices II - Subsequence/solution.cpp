class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int> > dp(n);
        int result = 0;

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                long long diff = (long)nums[i] - nums[j];
                dp[i][diff] += 1 + dp[j][diff];
                result += 1 + dp[j][diff];
            }
        }
        return result - (n * (n - 1) / 2);
    }
};