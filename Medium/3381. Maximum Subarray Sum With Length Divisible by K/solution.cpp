class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<long long> prefixSum(N + 1, 0);

        for (int i = 1; i <= N; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        vector<long long> minSumRem(N, 0);
        long long ans = LLONG_MIN;

        for (int i = 1; i <= N; i++){
            if (i < k){
                minSumRem[i] = prefixSum[i];
                continue;
            }

            minSumRem[i % k] = min(minSumRem[i % k], prefixSum[i - k]);
            ans = max(ans, prefixSum[i] - minSumRem[i % k]);
        }

        return ans;
    }
};