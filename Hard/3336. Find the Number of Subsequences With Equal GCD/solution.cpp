class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int N = nums.size();

        vector<vector<vector<int>>> dp(
            N, vector<vector<int>> (
                201, vector<int>(201, -1)
            )
        );

        int result = solve(0, 0, 0, nums, dp);

        return result; 
    }

    int gcd(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a == b) return a;
        if (a > b) return gcd(a - b, b);
        return gcd(a, b - a);
    }

    int solve(int idx, int left, int right, vector<int>& nums, vector<vector<vector<int>>> &dp){
        if (idx == nums.size()){
            if (left != 0 && right != 0 && left == right)   return 1;
            return 0;
        }

        if (dp[idx][left][right] != -1) return dp[idx][left][right];

        int MOD = 1e9 + 7;
        long long ret = 0;

        ret += solve(idx + 1, left, right, nums, dp);
        ret %= MOD;

        ret += solve(idx + 1, gcd(left, nums[idx]), right, nums, dp);
        ret %= MOD;

        ret += solve(idx + 1, left, gcd(right, nums[idx]), nums, dp);
        ret %= MOD;

        return dp[idx][left][right] = ret;
    }
};